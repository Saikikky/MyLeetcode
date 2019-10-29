class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int max = 0;
        while (i < j) {
            int h = 0;
            int tag = 1;
            if (height[i] < height[j]) {
                h = height[i];
                tag = 1;
            } else {
                h = height[j];
                tag = -1;
            }
            int temp = (j - i) * h;
            if (temp > max) max = temp;
            if (tag == 1) i++;
            else j--;
        }
        return max;
    }
}