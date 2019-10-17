class Solution {
    public int singleNumber(int[] nums) {
        int a = 0;
        for (int i = 0; i < nums.length; i++) {
            a ^= nums[i];
        }
        return a;
    }
}

如果我们对 0 和二进制位做 XOR 运算，得到的仍然是这个二进制位
a⊕0=a
如果我们对相同的二进制位做 XOR 运算，返回的结果是 0
a⊕a=0
XOR 满足交换律和结合律
a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
