import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

/**
 * dfs bfs应用
 * Created by Wangchen Yi on 16/3/6.
 */

/** 题目
*
*标题：穿越雷区
*
*X星的坦克战车很奇怪，它必须交替地穿越正能量辐射区和负能量辐射区才能保持正常运转，否则将报废。
*某坦克需要从A区到B区去（A，B区本身是安全区，没有正能量或负能量特征），怎样走才能路径最短？
*
*已知的地图是一个方阵，上面用字母标出了A，B区，其它区都标了正号或负号分别表示正负能量辐射区。
*例如：
*A + - + -
*- + - - +
*- + + + -
*+ - + - +
*B + - + -
*
*坦克车只能水平或垂直方向上移动到相邻的区。
*
*数据格式要求：
*
*输入第一行是一个整数n，表示方阵的大小， 4<=n<100
*接下来是n行，每行有n个数据，可能是A，B，+，-中的某一个，中间用空格分开。
*A，B都只出现一次。
*
*要求输出一个整数，表示坦克从A区到B区的最少移动步数。
*如果没有方案，则输出-1
*
*例如：
*用户输入：
*5
*A + - + -
*- + - - +
*- + + + -
*+ - + - +
*B + - + -
*
*则程序应该输出：
*10
*
*资源约定：
*峰值内存消耗（含虚拟机） < 512M
*CPU消耗  < 2000ms
*
*
*请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
*
*所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
*注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
*注意：主类的名字必须是：Main，否则按无效代码处理。
*
*
*
*/

public class Main
{
    //共用信息
    int n, answer = 10000; // n为输入迷宫大小 ans为最后解答输出数据
    public int [][]maze = new int[100][100]; //迷宫
    public boolean [][]visit = new boolean[100][100]; // 判断迷宫中的某店是否被输出
    int flag = 0;//用来判断当前的符号与下一个节点的符号相同不相同
    int xa, xb, ya, yb;//A B 两点的坐标

    //dfs
    ArrayList<Integer> arrayList = new ArrayList<>();

    //bfs用
    LinkedList<MazeNode> ll = new LinkedList<>();
    MazeNode[][] pre = new MazeNode[100][100]; // 深度优先搜索记录前面一个节点的信息,用于输出最终的答案

    //用于初始化迷宫信息,以及起始点A和终点B
    public void init()
    {
        String str; // 用于接受每一行输入的信息
        String []mazeStr; // 用于接受每一行输入的+ - 所分解的数组
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine(); // 用于吸收最后多出来的一个回车

        for (int i = 0; i< n; ++i)
        {
            str = sc.nextLine();
            mazeStr = str.split(" "); //分解当前输入的一行,分解后的结果放置与MazeStr中
            for (int j = 0; j < n; ++j)
            {
                if ("A".equals(mazeStr[j])) // 用 2 代替 A
                {
                    xa = i;
                    ya = j;
                    maze[i][j] = 2;
                }
                else if ("B".equals(mazeStr[j])) // 用 3 代替 B
                {
                    maze[i][j] = 3;
                    xb = i;
                    yb = j;
                }
                else if ("+".equals(mazeStr[j])) // 用 1 代替 +
                    maze[i][j] = 1;
                else if ("-".equals(mazeStr[j])) // 用 0 代替 -
                    maze[i][j] = 0;

                visit[i][j] = false; // 将所有的元素访问设置为 未访问状态
            }
        }

    }

    public void HandleStep()
    {
        int stap = 0; // 一共走过的步数
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
            {
//                System.out.print(visit[i][j] + "  ");  // 输出走过的路线
                if (visit[i][j])
                    ++stap;
            }
//            System.out.println();
        }
//        System.out.println(stap);
        arrayList.add(stap);  //将所有的结果添加到ArrayList中,最小的值为最优解,ArrayList长度为解的个数
    }

    //深度优先搜索的剪枝函数
    public boolean xianjie(int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n) // 越界处理
            return false;

        if (visit[i][j]) return false; // 访问处理

        if (flag == 0) return true; // 第一步回溯处理

        //下一节点与当前节点 + - 值相同处理
        if (flag == 1 && maze[i][j] == 1)return false;
        if (flag == -1 && maze[i][j] == 0) return false;

        return true;
    }

    public void dfs(int i, int j)
    {
        if (i == xb && j == yb)
        {
            //到达终点
            HandleStep(); //处理步数
        }
        else
        {
            for (int k = 1; k <= 4; k++) // 四叉树
            {
                if (xianjie(i, j))
                {
                    visit[i][j] = true; //先设置访问

                    if (maze[i][j] == 1) // 当前+ - 值
                        flag = 1;
                    else
                        flag = -1;

                    if (maze[i][j] == 2) // 小Bug改进 回溯到第一个点的时候将flag重新处理
                        flag = 0;

                    if (k == 1) //往上走
                        dfs(i -1, j);
                    if (k == 2) //往右走
                        dfs(i, j + 1);
                    if (k == 3) //往下走
                        dfs(i + 1, j);
                    if (k == 4) //往左走
                        dfs(i, j - 1);

                    if (maze[i][j] == 1)
                        flag = -1;
                    else
                        flag = 1;

                    visit[i][j] = false;

                }
            }
        }
    }



    //宽度优先搜索的剪枝函数
    public boolean isRightNode(MazeNode mazeNode)
    {
        if (mazeNode.i < 0 || mazeNode.j < 0 || mazeNode.i >= n || mazeNode.j >= n) // 越界
            return false;

        if (visit[mazeNode.i][mazeNode.j]) // 访问
            return false;

        if (flag == 0) return true; // 对第一个节点的特殊处理

        if (flag == 1 && maze[mazeNode.i][mazeNode.j] == 1) // 与dp剪枝思路相同
            return false;
        if (flag == -1 && maze[mazeNode.i][mazeNode.j] == 0)
            return false;

        return true;
    }

    public boolean bfs(MazeNode mazeNode) //有解返回真, 无解返回假, 输出最优解由打印完成
    {
        MazeNode nowNode;
        MazeNode nextNode = new MazeNode();
        ll.push(mazeNode); //将起始点放入队列中
        visit[mazeNode.i][mazeNode.j] = true; // 设置起始点 访问过状态

        while(!ll.isEmpty()) // 当栈空时还没有找到解,就是无解状态
        {
            nowNode = ll.pollFirst(); //出栈 为当前节点

            if (maze[nowNode.i][nowNode.j] == 1)
                flag = 1;
            else if (maze[nowNode.i][nowNode.j] == 0)
                flag = -1;

            for (int i = 0; i < 4; i++)
            {
                //设置四个方向的nextNode的值
                if (i == 0) nextNode = nextNode.up(nowNode);
                else if (i == 1) nextNode = nextNode.right(nowNode);
                else if (i == 2) nextNode = nextNode.down(nowNode);
                else nextNode = nextNode.left(nowNode);

                //成功
                if (nextNode.i == xb && nextNode.j == yb)
                {
                    //记录最后一步
                    pre[nextNode.i][nextNode.j] = nowNode;
                    return true;
                }

                //下一个节点可以访问
                if (isRightNode(nextNode))
                {
                    //按照bfs的思想添加进队列
                    ll.addLast(nextNode);
                    visit[nextNode.i][nextNode.j] = true; // 设置访问
                    pre[nextNode.i][nextNode.j] = nowNode; // 记录当前节点,使下一个节点能够访问,本身就是栈的思想
                }
            }
        }
        return false;
    }

    public void Print()
    {
        answer = 0;
        MazeNode temp = new MazeNode();
        Stack<MazeNode> s = new Stack<>(); //装最优解的栈
        temp.i = xb;
        temp.j = yb;

        while (temp.i != xa || temp.j != ya)
        {
            s.push(temp);
            temp = pre[temp.i][temp.j]; // 本身就是查找上一个节点的过程,从终点回溯到起点
        }

        while (!s.empty())
        {
            temp = s.peek();
            //System.out.println(temp.i + "  " +temp.j); // 打印最优解
            s.pop();
            answer++;
        }
    }


    public static void main(String []args)
    {

        //深度优先遍历
//        Main mm = new Main();
//        mm.init();
//        mm.dfs(mm.xa, mm.ya);
//
//        for (int i : mm.arrayList)
//        {
//            if (i < mm.answer) mm.answer = i;
//        }
//        System.out.print(mm.answer);



        //广度优先遍历
        Main mm = new Main();
        mm.init();

        MazeNode start = new MazeNode();//设置起始点
        start.i = mm.xa;
        start.j = mm.ya;

        if (mm.bfs(start)) // 如果有解
            mm.Print();

        System.out.print(mm.answer);

    }
}

class MazeNode
{
    int i, j; // 横纵坐标

    public MazeNode up(MazeNode m)
    {
        MazeNode x = new MazeNode();
        x.i = m.i - 1;
        x.j = m.j;
        return x;
    }

    public MazeNode right(MazeNode m)
    {
        MazeNode x = new MazeNode();
        x.i = m.i;
        x.j = m.j + 1;
        return x;
    }

    public MazeNode down(MazeNode m)
    {
        MazeNode x = new MazeNode();
        x.i = m.i + 1;
        x.j = m.j;
        return x;
    }

    public MazeNode left(MazeNode m)
    {
        MazeNode x = new MazeNode();
        x.i = m.i;
        x.j = m.j - 1;
        return x;
    }
}