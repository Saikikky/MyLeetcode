public class Solution {
    public int GetUglyNumber_Solution(int index) {
        if (index < 1) return 0;
        if (index == 1) return 1;
        int[] ugly = new int[index];
        ugly[0] = 1;
        // 记录到了2，3，5分别到了哪一个
        int i = -1, j = -1, k = -1;
        // 第i个丑数
        for (int tmp = 1; tmp < index; tmp++) {
            int ugly2 = 2 * ugly[i+1];
            int ugly3 = 3 * ugly[j+1];
            int ugly5 = 5 * ugly[k+1];

            int isMin = findMinNumber(ugly2, ugly3, ugly5);
            if (isMin == 2) {
                ugly[tmp] = ugly2;
                i++;
                if (ugly3 == ugly2) j++;
                if (ugly5 == ugly2) k++;
            } else if (isMin == 3) {
                ugly[tmp] = ugly3;
                j++;
                if (ugly3 == ugly2) i++;
                if (ugly5 == ugly3) k++;
            } else if (isMin == 5){
                ugly[tmp] = ugly5;
                k++;
                if (ugly3 == ugly5) j++;
                if (ugly2 == ugly5) i++;
            }
        }
        return ugly[index - 1];
    }
    public int findMinNumber(int a, int b, int c) {
        if (a <= b && a <= c) return 2;
        if (b < a && b <= c) return 3;
        if (c < a && c < b) return 5;
        return -1;
    }
}