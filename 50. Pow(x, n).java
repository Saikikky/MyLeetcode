class Solution {
    public double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;

        int t = n / 2;
        if (n < 0) {
            t = -t;
            x = 1/x;
        }

        double res = myPow(x, t);
        if (n % 2 == 0) return res*res;
        else return res*res*x;
    }
}