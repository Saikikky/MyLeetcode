/**
 * 输出字符串的所有组合
 * abc
 * a,b,c,ab,bc,ac,abc
 */


/**
 * 递归解法 时间复杂度O(n^2)
 */
public class Solution {

    public static void combine(char[] chars, int begin, int len, StringBuffer sb) {
        if (len == 0) {
            System.out.println(sb);
            return;
        }
        if (begin == chars.length) return;
        // 取当前字符
        sb.append(chars[begin]);
        combine(chars, begin + 1, len - 1, sb);
        // 不取当前字符
        sb.deleteCharAt(sb.length() - 1);
        combine(chars, begin + 1, len, sb);
    }

    public static void main(String[] args) {
        String str = "abc";
        char[] chars = str.toCharArray();
        StringBuffer sb = new StringBuffer();
        for (int i = 1; i <= chars.length; i++) {
            combine(chars, 0, i, sb);
        }
    }


    /**
     * 二进制解法
     */
    public class Solution {

        public static void combine(char[] chars) {
            if (chars == null) return;
            int len = chars.length;
            boolean used[] = new boolean[len]; // 默认为false
            char cache[] =  new char[len];
            int result = len;
            while (true) {
                int index = 0;
                while (used[index]) {
                    used[index] = false;
                    ++result;
                    if (++index == len) return;
                }
                used[index] = true;
                cache[--result] = chars[index];
                System.out.println(new String(cache).substring(result) + " ");
            }

        }

        public static void main(String[] args) {
            String str = "abc";
            char[] chars = str.toCharArray();
            combine(chars);

        }
    }

    //  二进制最终解法
    public static void main(String[] args) {
        //String str[] = {"A", "B", "C", "D"};
        String a = "ABC";
        char[] str = a.toCharArray();
        int length = str.length;
        // 得到2^n 个1
        int nbit = (0xFFFFFFFF >>> (32 - length));
        for (int i = 1; i <= nbit; i++) {
            for (int j = 0; j < length; j++) {
                // 将1向左移动j位(等价于1*2^j) 按位与i 判断结果是否为0
                // 1<<i 是将1左移i位，即第i位为1，其余位为0；
                // n&(1<<i)是将左移i位的1与n进行按位与，即为保留n的第i位，其余位置零
                if ((1 << j & i) != 0) {
                    System.out.print(str[j]);
                }
            }
            System.out.println(" ");
        }
    }
}