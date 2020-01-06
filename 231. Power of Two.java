class Solution {
    public boolean isPowerOfTwo(int n) {
        return (n > 0) && (n & (n - 1)) == 0;
    }
}


/**
n:      ******10000
n-1:    ******01111
n&(n-1):******00000
若n中只有一个1，n&(n-1)一定为0
**/