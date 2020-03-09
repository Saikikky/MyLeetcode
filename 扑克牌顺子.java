import java.util.TreeSet;
public class Solution {
    public boolean isContinuous(int [] numbers) {
        if (numbers.length < 5) return false;

        int count = 0;
        TreeSet<Integer> treeSet = new TreeSet<>();
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == 0) count++;

            else treeSet.add(numbers[i]);
        }

        if (treeSet.size() + count != 5) return false;
        if (treeSet.last() - treeSet.first() >= 5) return false;
        return true;
    }
}