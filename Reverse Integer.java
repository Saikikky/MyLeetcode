import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
    public int reverse(int x) {
        int tag = 0;
        if (x < 0) {
            tag = 1;
        }
        long number = Math.abs((long)x);
        long sum = 0;
        while (number != 0) {
            sum = number % 10 + sum * 10;
            number /= 10;
        }
        if (tag == 1) sum = -sum;
        return (sum > Integer.MAX_VALUE || sum < Integer.MIN_VALUE) ? 0 : (int)sum;

    }
}

public class MainClass {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int x = Integer.parseInt(line);

            int ret = new Solution().reverse(x);

            String out = String.valueOf(ret);

            System.out.print(out);
        }
    }
}