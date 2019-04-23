import java.text.DecimalFormat;
import java.util.*;

/**
 * Created by wang on 16/7/10.
 */
public class L209 {
    public static void main(String [] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat(".00");
        int num,people, getmoney;
        int [] get = new int[10000];
        int [] pay = new int[10000];
        S [] s = new S[10000];
        HashMap <Integer, S> hashMap = new HashMap<Integer, S>();
        n = sc.nextInt();
        for (int i = 0; i < 10000; ++i)
            s[i] = new S();
        for (int i = 1; i <= n; ++i)
        {
            num = sc.nextInt();
            for (int j = 1; j <= num; ++j)
            {
                people = sc.nextInt();
                getmoney =  sc.nextInt();
                get[people] += getmoney;
                ++s[people].num;
                pay[i] -= getmoney;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            s[i].sum = get[i] + pay[i];
            hashMap.put(i, s[i]);
        }

        List<Map.Entry<Integer, S>> list = new ArrayList<Map.Entry<Integer, S>>(hashMap.entrySet());

        Collections.sort(list, new Comparator<Map.Entry<Integer, S>>() {
            @Override
            public int compare(Map.Entry<Integer, S> o1, Map.Entry<Integer, S> o2) {
                if (o1.getValue().sum < o2.getValue().sum) // 钱按降序
                    return 1;
                else if (o1.getValue().sum == o2.getValue().sum) // 如果输入金额有并列
                {
                    if (o1.getValue().num < o2.getValue().num) // 则按抢到红包个数递减
                        return 1;
                    else if (o1.getValue().num == o2.getValue().num)
                    {
                        if (o1.getKey() < o2.getKey())
                            return -1;
                        else
                            return 1;
                    }
                    else
                        return -1;
                }
                else
                    return -1;
            }
        });

        for (int i = 0; i < n; ++i)
        {
            System.out.println(list.get(i).getKey() + " " +
                    df.format(list.get(i).getValue().sum / 100.0));
//            System.out.print(list.get(i).getValue().num);
        }
    }
}

class S
{
    int sum;
    int num;
}
