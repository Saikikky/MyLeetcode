/**
找有几个零就是找有几个2*5 由于2的个数一定大于5，找到5的个数就知道有几个0了
**/
class Solution {
    public int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            count += (n / 5);
            n /= 5;
        }
        return count;
    }
}