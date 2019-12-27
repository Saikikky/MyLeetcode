/**
一种优化后的求质数的方法
**/

class Solution {
    public int countPrimes(int n) {
        boolean[] nums = new boolean[n];
        Arrays.fill(nums, true);
        for (int i = 2; i < n; i++) {
            if (nums[i] == true) {
                for (int j = 2*i; j < n; j+=i) {
                    nums[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] == true) count++;
        }
        return count;

    }

}



/**
当判断某个数是否为质数的时候这个方法很不错
**/

 /**
     * 判断质数的其中一种比较高效的方法
     * @param num
     * @return
     */

    public static boolean isPrime(int num) {
        if (num <= 3) {
            return num > 1;
        }
        // 不在6的倍数两侧的一定不是质数
        if (num % 6 != 1 && num % 6 != 5) {
            return false;
        }
        int sqrt = (int) Math.sqrt(num);
        for (int i = 5; i <= sqrt; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
