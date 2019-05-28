public class Solution {


    public static int partition(int[] a, int left, int right) {
        // 取第一个数为基准
        int temp = a[left];
        while (right > left) {
            // 先判断基准数跟后面的数比大小
            while (temp <= a[right] && left < right) --right;
            // 基准数大于right
            if (left < right) {
                a[left] = a[right];
                ++left;
            }
            // 此时用该值与left比大小
            while (temp >= a[left] && left < right) ++left;
            // 此时temp < a[left]
            if (left < right) {
                a[right] = a[left];
                --right;
            }
        }
        a[left] = temp;
        return left;
    }
    public static void quickSort(int[] a, int left, int right) {
        if (a == null || left >= right || a.length <= 1) return;
        int mid = partition(a, left, right);
        quickSort(a, left, mid);
        quickSort(a, mid + 1, right);
    }
    public static void main(String[] args) {
        int a[] = {2, 4, 1, 7, 10, 6, 3};
        quickSort(a, 0, a.length - 1);
    }
}