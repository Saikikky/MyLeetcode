public class Solution {
    public int NumberOf1(int n) {
        /**
        把一个整数减去1，再和原来的整数做相与运算，会把该整数二进制的最右边的1变成0。
        那么根据上述的原理，一个整数中有多少个1，就可以进行多少次上述的相与运算。根据这种思路，可以写出更加高效的算法。
        **/
        int sum = 0;
        while (n != 0) {
            sum++;
            n = n&(n-1);
        }
        return sum;
        /*
        int tmp = 1;
        int sum = 0;
        while (tmp != 0) {
            if ((n & tmp) != 0) sum++;
            tmp = tmp << 1;
        }
        return sum;*/
        /*
        int tmp = 1;
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            if ((n&tmp) != 0) {
                sum++;
            }
            tmp = tmp<<1;
        }
        return sum;  */ 
    }
}