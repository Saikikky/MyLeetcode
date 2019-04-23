import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

/**
 * Created by Treasure_ on 16/3/6.
 */
public class Main
{
    public static void main(String[] args)
    {
        //对 bg1 进行赋值 ZERO ONE TEN 三个选项
        BigInteger bg1 = BigInteger.ONE;    //  输出1

        //BigInteger 构造赋值
        BigInteger bg2 = new BigInteger("999999999999999");//   输出123

//        byte []bytes = {};
//        BigInteger bg3 = new BigInteger(bytes);
//        System.out.print(bg3.toString());


        // ------------------- 用法 --------------------
        // 加法
        bg1 = bg1.add(bg2);//输出   1000000000000000

        //减法
        BigInteger bg3 = bg1.subtract(bg2); //输出 1

        //乘法
        bg3 = bg2.multiply(bg2); //输出 999999999999998000000000000001

        //除法
        bg3 = bg2.divide(bg2); // 输出1

        bg3 = bg3.add(bg3);
        bg3 = bg3.pow(11213); //2 ^ 11213

        //其他常用简单函数
        /*
        * BigInteger.abs()
        *
        * BigInteger.doubleValue()  转化为double  --> floatValue()   --> intValue()  --> longValue()
        *
        * boolean BigInteger.equals(Object x)  与 x 进行比较
        *
        * BigInteger gcd(BigInteger val)  返回一个 BigInteger，其值是 abs(this) 和 abs(val) 的最大公约数
        *
        * boolean isProbablePrime(int certainty)
        * certainty - 调用方允许的不确定性的度量。如果该调用返回 true，
        * 则此 BigInteger 是素数的概率超出 (1 - 1/2certainty)。此方法的执行时间与此参数的值是成比例的
        *
        * max , min , mod , pow , gcd, negate(求负数)

        * */

        //用String 与 用 Double 创建的BigDecimal不相同
        BigDecimal bd1 = new BigDecimal("123.12");
        BigDecimal bd2 = new BigDecimal(123.123);

//        System.out.println(bd1.toString() + "  " + bd1.scale()); //123.12  2
//        System.out.println(bd2.toString() + "  " + bd2.scale()); //123.1230000000000046611603465862572193145751953125  46
//
//        System.out.println(bd1.negate().toString()); //取负
//        System.out.println(bd1.plus().toString());//取正 没啥用
//        System.out.println(bd1.precision()); // 精度 输出5 精度要加上前面的整数位
//        System.out.println(bd2.precision()); // 精度 输出49


//        BigDecimal bd3 = new BigDecimal("456.73");
//        System.out.println(bd1.add(bd3).toString()); // 直接相加, scale取大的  输出579.909
//
//        // 根据 MathContext设置的精度确定,如果精度比整数位数还小,就用科学计数法输出 比整体位数大则不变
//        System.out.println(bd1.add(bd3, new MathContext(2)).toString());

        //减法, 乘法用法相同
    }
}
