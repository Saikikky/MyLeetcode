/**
位运算 用每一位跟1异或
异或同为1异为0
**/
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int tmp = 1;
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            if ((n&tmp) != 0) {
                sum++;
            }
            tmp = tmp<<1;
        }
        return sum;
    }
}