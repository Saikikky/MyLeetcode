import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * Created by Treasure_ on 16/3/16.
 */

/*反片语

输入一些单词，找出所有满足如下条件的单词，该单词不能通过字母重排，得到输入文本中的另一个单词。在判断是否满足条件时，
字母不分大小写，但在输出时应保留输入中的大小写，按字典序进行排列（所有大写字母在所有小写字母的前面）。＃代表结束输入

样例输入：
ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCes drIed
noel dire Disk mace Rob dries
#

样例输出：
Disk
NotE
derail
drIed
eye
ladder
soon

*/

public class Main
{
    public static void main(String [] args)
    {

        //前期处理字符串转化为小写的变量
        String strLine; // 接受每一行输入的全部字符
        String [] str; // 将每一行输入的字符串去掉中间的空格存储在str中
        char []ch;
        //其实也可以不使用temp,直接用Arrays 里面的toString判断效果相同
        StringBuffer temp = new StringBuffer(); //将排序过后的字符数组转化为StringBuffer再转化为String类型

        //将排序过后的原本字符串和小写字符串保存在数组中
        Oppose[] a = new Oppose[100];
        int arrayLength = 0; //记录Oppose数组的长度

        // 存储最后的答案字符串数组
        String[] ans = new String[50];
        int ansTime = 0; //ans 数组的长度

        int d, i; //在最后计算是否有重复  循环节

        Scanner sc = new Scanner(System.in);

        strLine = sc.nextLine();

        //将字符串小写排序 并且把组合添加进Oppose数组中
        while(!"#".equals(strLine))
        {
            str = strLine.split(" ");
            for (String x : str)
            {
                temp.delete(0, temp.capacity()); // temp清空
                a[arrayLength] = new Oppose();
                a[arrayLength].s = x;
                x = x.toLowerCase();
                ch = x.toCharArray();
                Arrays.sort(ch);
                temp.append(ch);
                a[arrayLength].e = temp.toString();
                ++arrayLength;
            }
            strLine = sc.nextLine();
        }

        //按小写排序
        Arrays.sort(a, 0, arrayLength, new Comparator<Oppose>() {
            @Override
            public int compare(Oppose o1, Oppose o2) {
                return o1.e.compareTo(o2.e); // 自然顺序 a -> z
//                return o2.e.compareTo(o1.e); // 反自然顺序 z -> a
            }
        });

        //处理排序的结果 让后把结果
        for (i = 0; i < arrayLength; ++i)
        {
            d = 1;
            for (int j = i + 1; j < arrayLength; ++j)
            {
                if (a[i].e.equals(a[j].e))
                {
                    d++;
                }
                else
                {
                    i = j - 1;
                    break;
                }
            }

            if (d == 1)
            {
                ans[ansTime] = a[i].s;
                ++ansTime;
            }

        }

        //排序输出
        Arrays.sort(ans, 0, ansTime);

        for (int j = 0; j < ansTime; ++j)
        {
            System.out.println(ans[j]);
        }

    }
}

class Oppose
{
    public String s;
    public String e;
}
