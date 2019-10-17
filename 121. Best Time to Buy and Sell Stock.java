/**
 * 第一个解法 用时太长且占内存太大
 * @param prices
 * @return
 */
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        for (int i = 0; i < prices.length; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                if (prices[j] > prices[i]) {
                    int temp = prices[j] - prices[i];
                    if (temp > max) max = temp;
                }
            }
        }
        return max;
    }
}


/**
 * 第二个解法直接按照顺序从头到尾就可以判断是否在买入之后买进
 * @param prices
 * @return
 */
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;
        int max = 0;
        int min = prices[0];
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                int temp = prices[i] - min;
                if (temp > max) max = temp;
            }
        }
        return max;
    }
}