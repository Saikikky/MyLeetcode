import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
       ArrayList<ArrayList<Integer>> results = new ArrayList<>();
        int low = 1, high = 2;
        while (low < high) {
            int res = (low + high) * (high - low + 1) / 2;
            if (res == sum) {
                ArrayList<Integer> result = new ArrayList<>();
                for (int i = low; i <= high; i++) {
                    result.add(i);
                }
                results.add(result);
                low++;
            } else if (res < sum) {
                high++;
            } else {
                low++;
            }
        }
        return results;
    }
}