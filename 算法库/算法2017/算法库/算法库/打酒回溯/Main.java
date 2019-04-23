/**
 * Created by Treasure_ on 16/3/2.
 */

//原本两斗酒  最后一次遇到的是花 酒喝完了
public class Main
{
    int []a = new int[100];
    int n = 15;
    static int count = 0; //输出总量
    int jiu = 2; //酒量
    int countD = 0;
    int countH = 0;
//    int n1 = 5; //遇到店 加一倍
//    int n2 = 10; //遇到花 喝一斗


    public boolean xianjie(int k, int i)
    {
        if (i == 1 && countD + 1 > 5) return false;
        if (i == 2 && countH + 1 > 10) return false;
        return true;
    }

    public void dfs(int k)
    {
        if (k == n + 1 && countD == 5 && countH == 10 && jiu == 0 && a[15] == 2)
        {
            ++count;
        }
        else
        {
            for (int i = 1; i <= 2; i++) //1 代表店 2代表花
            {
                if (xianjie(k, i))
                {
                    a[k] = i;
                    if (i == 1)
                    {
                        ++countD;
                        jiu *= 2;
                    }
                    if (i == 2)
                    {
                        ++countH;
                        jiu -= 1;
                    }

                    dfs(k + 1);

                    if (i == 1)
                    {
                        countD--;
                        jiu/= 2;
                    }
                    if (i == 2)
                    {
                        countH--;
                        jiu+=1;
                    }
                }

            }
        }
    }

    public static void main(String [] args)
    {
        Main mm = new Main();
        mm.dfs(1);
        System.out.print(count);
    }
}
