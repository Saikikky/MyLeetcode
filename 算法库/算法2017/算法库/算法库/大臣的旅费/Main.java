import java.util.Scanner;

/**
 * Created by Treasure_ on 16/3/18.
 */

/**标题：大臣的旅费
很久以前，T王国空前繁荣。为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。
为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者
通过其他大城市间接到达。同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。

J是T国重要大臣，他巡查于各大城市之间，体察民情。所以，从一个城市马不停蹄地到另一个城市成了J最常做的
事情。他有一个钱袋，用于存放往来城市间的路费。

聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千
米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。

J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？

输入格式：
输入的第一行包含一个整数n，表示包括首都在内的T王国的城市数
城市从1开始依次编号，1号城市为首都。
接下来n-1行，描述T国的高速路（T国的高速路一定是n-1条）
每行三个整数Pi, Qi, Di，表示城市Pi和城市Qi之间有一条高速路，长度为Di千米。

输出格式:
输出一个整数，表示大臣J最多花费的路费是多少。

样例输入:
5
1 2 2
1 3 1
2 4 5
2 5 4

样例输出:
135

样例说明:
大臣J从城市4到城市5要花费135的路费。
*/


public class Main
{
    final int moneyCostMax = 1000;
    final int maxCityNumber = 1001;

    int n; // 城市数
    int [][] distance = new int[maxCityNumber * 2][4]; // 任意两城市之间的距离
    int [] moneyCost = new int[moneyCostMax];      //花钱的总数 0 为空, moneyCost[1]表示走一公里需要多少钱
    int [][] allDistance = new int[maxCityNumber][maxCityNumber];  // 所有城市之间的距离
    int [][] route = new int[maxCityNumber][3];            // 从一个城市到另外一个城市的路线
    int depth = 0; //计算所有距离时的递归深度

    public void init()
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        //输入第一轮数据
        for(int i = 0; i < (n - 1); ++i)
        {
            for (int j = 0; j <= 2; ++j)
            {
                distance[i][j] = sc.nextInt();
            }
        }

        //计算第二轮数据
        for (int i = n - 1, q = 0; i < (n - 1) * 2; ++i, ++q)
        {
            distance[i][0] = distance[q][1];
            distance[i][1] = distance[q][0];
            distance[i][2] = distance[q][2];
        }

        //输出检查
//        for (int i = 0; i < (n - 1) * 2; ++i)
//        {
//            for (int j = 0; j < 3; ++j)
//            {
//                System.out.print(distance[i][j] + " ");
//            }
//            System.out.println();
//        }

        //计算一共需要多少钱
        moneyCost[0] = -1;
        moneyCost[1] = 11;
        for (int i = 2; i < moneyCostMax; ++i)
        {
            moneyCost[i] = moneyCost[i - 1] + i + 10;
        }
    }

    public void PutDistance() // 计算从随便一个点到任意点的距离 --> 填充二维数组
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    allDistance[i][j] = 0; // 本身到本身的距离为 0
                else
                {
                    //求从 i 号城市 到 j 号城市的距离
                    if (allDistance[j][i] != 0)
                        allDistance[i][j] = allDistance[j][i]; //如果对应的城市存在,直接复制
                    else
                    {
                        depth = 0; // 每次计算之前深度归零
                        allDistance[i][j] = CalDistance(i, j); //计算从 i 城市 到 j城市的距离
                    }
                }
            }
        }

        //查看所有距离
//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 1; j <= n; ++j)
//            {
//                System.out.print(allDistance[i][j] + " ");
//            }
//            System.out.println();
//        }
    }

    public int CalDistance(int p, int q) //求从 p 号城市 到 q 号城市的距离
    {
        int temp; // 计算下一轮的距离值
        int allDis = 0; // 该轮的距离值

        for (int i = 0; i < depth; i++) //如果找到回路,就直接返回0 然后跳到下行 distance进行计算
        {
            if (p == route[i][0] && q == route[i][1])
                return 0;
        }
        route[depth][0] = p; // 存储当前的路径
        route[depth][1] = q;
        ++depth;

        for (int i = 0; i < (n - 1) * 2; ++i)
        {
            if (distance[i][0] == p && distance[i][1] == q) // 如果直接找到,就直接返回
                return distance[i][2];
        }


        for (int i = 0; i < (n - 1) * 2; ++i)
        {
            if (distance[i][0] == p)// 从p出发的深度优先的计算,让与p相连的下一个点为起点进行下一轮计算
            {
                temp = CalDistance(distance[i][1], q); // 计算由当前行所延伸下去的下一个值
                if (temp == 0) continue; // 找到回路或者没有路 直接进行下一轮的计算
                allDis = distance[i][2] + temp; // 找到了路,加上当前的路径长度为目前的总长度
            }
        }
        return allDis;
    }

    public int MaxRoute() //求出二维数组中的最大值
    {
        int max = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j >= n) continue; //只计算一半的数据
                if (max < allDistance[i][j])
                    max = allDistance[i][j];
            }
        }
        return max;
    }


    public static void main(String [] args)
    {
        Main mm = new Main();
        mm.init();
        mm.PutDistance();
        System.out.print(mm.moneyCost[mm.MaxRoute()]);
    }
}
