/**
位运算更快
**/
public class Solution {
    public double Power(double base, int exponent) {
        double res = 1, cur = base;
        int tmp;
        if (exponent  < 0) {
            tmp = -exponent;
        } else if (exponent > 0) {
            tmp = exponent;
        } else {
            return 1;
        }
        while (tmp != 0) {
            System.out.println("tmp:" + tmp);
            System.out.println("res:" + res);
            if ((tmp & 1) == 1) {
                res *= base;
            }
            base *= base;
            // 除2
            tmp >>= 1;
        }
        return exponent > 0 ? res : (1.0/res);
  }
}




public class Solution {
    public double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        if (exponent > 1) {
            double result = Power(base, exponent/2);
            result *= result;
            if ((exponent & 1) == 1) {
                result *= base;
            }
            return result;
        }
        if (exponent < 0) {
            exponent = -exponent;
            double result = Power(base, exponent);
            return 1/result;
        }
        return -1;
  }
}