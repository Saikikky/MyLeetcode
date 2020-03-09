public class Solution {
    public int Add(int num1,int num2) {
        while (num2 != 0) {
            // 不进位的部分
            int temp = num1 ^ num2;
            // 进位部分 直到进位为0
            num2 = (num1 & num2) << 1;
            num1 = temp;
        }
        return num1;
    }
}