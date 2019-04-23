import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

/**
 * Created by Treasure_ on 16/3/18.
 */

public class Main
{
    //c++
//    int sqrt(float x) {
//        if(x == 0) return 0;
//        float result = x;
//        float xhalf = 0.5f*result;
//        int i = *(int*)&result;
//        i = 0x5f375a86- (i>>1); // what the fuck?
//        result = *(float*)&i;
//        result = result*(1.5f-xhalf*result*result); // Newton step, repeating increases accuracy
//        result = result*(1.5f-xhalf*result*result);
//        return 1.0f/result;
//    }

    double precision = 0.0000000001;
    int n = 5;
    BigDecimal bigN = new BigDecimal("5");
    BigDecimal bigPrecision = new BigDecimal("1E-140");


    //老老实实的牛顿迭代 (递归方法)
//    double f(double x0)
//    {
//        double y, x1;
//        x1 = (x0 + n / x0) / 2.0;
//        if (Math.abs(x1 - x0) > precision)
//        {
//            y = f(x1);
//        }
//        else
//        {
//            y = x1;
//        }
//        return y;
//    }

    //非递归方法
//    public double f(double x)
//    {
//        double x1;
//        while (true)
//        {
//            x1 = (x + n / x) / 2.0;
//            if (Math.abs(x1 - x) < precision)
//                break;
//            x = x1;
//        }
//        return x1;
//    }

    //大整数运算方法
//    public BigDecimal f(BigDecimal x)
//    {
//        BigDecimal x1;
//        while(true)
//        {
//            x1 = (x.add(bigN.divide(x, new MathContext(150)))).divide(new BigDecimal("2"));
//            if (x1.subtract(x).abs().compareTo(bigPrecision) < 0)
//                break;
//            x = x1;
//        }
//        return x1;
//    }

    public static void main(String [] args)
    {
        System.out.println(new Main().f(new BigDecimal("1")).subtract(new BigDecimal("1"))
                .divide(new BigDecimal("2"), new MathContext(150)));
    }
}
