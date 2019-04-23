/**
 * Created by Treasure_ on 16/3/9.
 */

/*题目描述
*
*
标题：六角幻方

    把 1 2 3 ... 19 共19个整数排列成六角形状，如下： 19 * 20 / 2 = 190  每一行 190 / 5 = 38

    * * *
   * * * *
  * * * * * // 求
   * * * *
    * * *

    要求每个直线上的数字之和必须相等。共有15条直线哦！

    再给点线索吧！我们预先填好了2个数字，第一行的头两个数字是：15 13，参见图【p1.png】，黄色一行为所求。

    请你填写出中间一行的5个数字。数字间用空格分开。

    这是一行用空格分开的整数，请通过浏览器提交答案，不要填写任何多余的内容（比如说明性的文字等）

* */

public class Main
{
    int a= 38;
    public int n = 19;
    public int []ans = new int[100];
    public boolean [] visit = new boolean[100];

    public boolean xianjie(int k, int i)
    {
        if (visit[i])
            return false;
        if (k == 1 && i != 15)
            return false;
        if (k == 2 && i != 13)
            return false;

        if (k == 4 && ans[1] + ans[2] + ans[3] != a)
            return false;

        if (k == 8 && ans[4] + ans[5] + ans[6] + ans[7] != a)
            return false;

        if (k == 9 && ans[1] + ans[4] + ans[8] != a)
            return false;

        if (k == 13 && ans[8] + ans[9] + ans[10] + ans[11] + ans[12] != a)
            return false;

        if (k == 13 && ans[3] + ans[7] + ans[12] != a)
            return false;

        if (k == 14 && ans[2] + ans[5] + ans [9] + ans[13] !=a)
            return false;

        if (k == 17 && ans[13] + ans[14] + ans[15] + ans[16] != a)
            return false;

        if (k == 17 && ans[2] + ans[6] + ans[11] + ans[16] != a)
            return false;

        if (k == 18 && ans[3] + ans[6] + ans[10] + ans[14] + ans[17] != a)
            return false;

        if (k == 18 && ans[8] + ans[13] + ans[17] != a)
            return false;

        if (k == 19 && ans[7] + ans[11] + ans[15] + ans[18] != a)
            return false;

        if (k == 19 && ans[4] + ans[9] + ans[14] + ans[18] != a)
            return false;
        return true;
    }

    public boolean Ans()
    {
        if (ans[17] + ans[18] + ans[19] != a)
            return false;
        if (ans[12] + ans[16] + ans[19] != a)
            return false;
        if (ans[1] + ans[5] + ans[10] + ans[15] + ans[19] != a)
            return false;
        return true;

    }
    public void dfs(int k)
    {
        if (k == n + 1 && Ans())
        {
            for (int i = 8; i <= 12; ++i)
            {
                System.out.print(ans[i] + "  ");
            }
            System.out.println();
        }
        else
        {
            for (int i = 1; i <= 19; i++)
            {
                if (xianjie(k, i))
                {
                    ans[k] = i;
                    visit[i] = true;
                    dfs(k + 1);
                    visit[i] = false;
                }
            }
        }
    }
    public static void main(String [] args)
    {
        long startTime = System.currentTimeMillis();
        Main mm = new Main();
        for (int i = 0; i < 100; i++)
        {
            mm.visit[i] = false;
        }

        mm.dfs(1);

        long endTime = System.currentTimeMillis();

        System.out.println("用时" + (endTime - startTime) / 1000 + "s");
    }


}
