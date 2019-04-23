/**
 * Created by Treasure_ on 16/3/9.
 */

/*题目描述
*
*
标题：四阶幻方

把1~16的数字填入4x4的方格中，使得行、列以及两个对角线的和都相等，满足这样的特征时称为：四阶幻方。

四阶幻方可能有很多方案。如果固定左上角为1，请计算一共有多少种方案。
比如：
  1  2 15 16
 12 14  3  5
 13  7 10  4
  8 11  6  9

以及：
  1 12 13  8
  2 14  7 11
 15  3 10  6
 16  5  4  9

就可以算为两种不同的方案。

请提交左上角固定为1时的所有方案数字，不要填写任何多余内容或说明文字。



* */
public class Main
{
    int count = 0;
    public int n = 16;
    public boolean[] visit = new boolean[100];
    public int [] ans = new int[100];

    public boolean xianjie(int k, int i)
    {

        if (k == 1 && i != 1)
            return false;

        if (k == 5 && (ans[1] + ans[2] + ans[3] + ans[4] != 34))
            return false;

        if (k == 9 && (ans[5] + ans[6] + ans[7] + ans[8] != 34))
            return false;

        if (k == 13 && (ans[9] + ans[10] + ans[11] + ans[12] != 34))
            return false;

        if (k == 14 && (ans[13] + ans[4] + ans[7] + ans[10] != 34))
            return false;

        if (k == 14 && (ans[1] + ans[5] + ans[9] + ans[13] != 34))
            return false;

        if (k == 15 && ans[2] + ans[6] + ans[10] + ans[14] != 34)
            return false;

        if (k == 16 && ans[3] + ans[7] + ans[11] + ans[15] != 34)
            return false;
        return true;
    }

    public boolean Ans()
    {
        if (ans[13] + ans[14] + ans[15] + ans[16] == 34 && ans[1] + ans[6] + ans[11] + ans[16] == 34
                && ans[4] + ans[8] + ans[12] + ans[16] == 34)
            return true;
        return false;
    }

    public void dfs(int k)
    {
        if (k == n + 1 && Ans())
        {
            count++;
        }
        else
        {
            for (int i = 1; i <= 16; ++i)
            {
                if (xianjie(k, i) && !visit[i])
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
        for (int i = 0; i < 100; ++i)
        {
            mm.visit[i] = false;
        }
        mm.dfs(1);
        System.out.println(mm.count);
        long endTime = System.currentTimeMillis();
        System.out.print("用时" + (endTime - startTime)/1000 + "s");
    }
}
