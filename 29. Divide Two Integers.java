/**
任何一个整数可以表示成以2的幂为底的一组基的线性组合，即num=a02^0+a12^1+a22^2+…+an2^n。
基于以上这个公式以及左移一位相当于乘以2，我们先让除数左移直到大于被除数之前得到一个最大的基0。
然后接下来我们每次尝试减去这个基，如果可以则结果增加加2^k,然后基继续右移迭代，直到基为0为止。
因为这个方法的迭代次数是按2的幂知道超过结果，所以时间复杂度为O(log(n))。

即转换被除数为dividend = divisor * 2^m + divisor * 2^n + divisor * 2^o + ... + y(m > m > o>.....，且y < divisor)

那么被除数 dividend 除以除数 divisor 的商为2^m + 2^n + 2^o + ....

注：考虑溢出，当被除数为-2^31，除数为-1，商为2^31，会溢出
**/
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;

        long d = Math.abs((long) dividend), b = Math.abs((long) divisor), res = 0;
        if (b == 1) {
            return (int)(((dividend < 0) ^ (divisor < 0) ? d*-1 : d));
        }

        while (d >= b) {
            long tmp = b, p = 1;
            while (d >= (tmp << 1)) {
                tmp <<= 1;
                p <<= 1;
            }
            d -= tmp;
            res += p;
        }
        return (int)(((dividend < 0) ^ (divisor < 0)) ? -res : res);
    }
}