public class Solution {
    int count;
    public int InversePairs(int [] array) {
        MergeSort(array, 0, array.length - 1);
        return count;
    }
    
    public void MergeSort(int[] array, int start, int end) {
        if (start < end) {
            int pos = (start + end) / 2;
            MergeSort(array, start, pos);
            MergeSort(array, pos+1, end);
            Merge(array, start, pos, end);
        }

    }

    public void Merge(int[] array, int start, int pos, int end) {
        int[] tmp = new int[end - start + 1];
        int i = start, j = pos + 1;
        int k = 0;
        while (i <= pos && j <= end) {
            if (array[i] < array[j]) {
                tmp[k++] = array[i++];
            } else {
                tmp[k++] = array[j++];
                count += pos-i+1;
                count %= 1000000007;
            }
        }
        while (i <= pos) {
            tmp[k++] = array[i++];
        }
        while (j <= end) {
            tmp[k++] = array[j++];
        }

        for (i = 0; i < k; i++) {
            array[start + i] = tmp[i];
        }
    }
}