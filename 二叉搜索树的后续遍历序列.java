public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if (sequence == null || sequence.length == 0) return false;
        if (sequence.length == 1) return true;
        return f(sequence, 0, sequence.length-1);
    }
    
    public boolean f(int[] sequence, int start, int end) {
        // start==end时是叶子节点 start>end时是空树
        if (start >= end) return true;
        int root = sequence[end];
        int pos = -1;
        int i = 0;
        while (i < end && sequence[i]<root) i++;

        for (int k = i; k < end; k++) {
            if (sequence[k] < root) return false;
        }

        return f(sequence, start, pos-1) && f(sequence, pos, end-1);
    }
}