import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer> results = new ArrayList<>();
        if (num == null || num.length == 0 || size == 0) return results;

        int start = Integer.MIN_VALUE;
        int max = Integer.MIN_VALUE;

        int i = 0, j = i + size - 1;
        int tag = 1;
        while (j < num.length) {
            if (tag == 1) {
                // 第一次需要对比所有的
                for (int k = i; k <= j; k++) {
                    if (num[k] > max) {
                        max = num[k];
                    }
                }
                results.add(max);
                tag++;
            } else {
                int temp = results.get(results.size() - 1);
                if (start != temp) {
                    if (num[j] > temp) {
                        results.add(num[j]);
                    } else {
                        results.add(temp);
                    }
                } else {
                    for (int k = i; k <= j; k++) {
                        if (num[k] > max) {
                            max = num[k];
                        }
                    }
                    results.add(max);
                }
            }
            start = num[i];
            i++;
            j++;
            max = Integer.MIN_VALUE;
        }
        return results;
    }
}