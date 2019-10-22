class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] sum = new int[2];
        int i = 0, j = numbers.length - 1;
        while (i < numbers.length && j >= 0) {
            if (i == j) continue;
            if (numbers[i] + numbers[j] == target) {
                sum[0] = i + 1;
                sum[1] = j + 1;
                break;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return sum;
    }
}