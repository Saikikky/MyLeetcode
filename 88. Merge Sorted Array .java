public class MergeSortedArray {

    public static void main(String[] args) {
        int[] nums1 = {2, 0};
        int[] nums2 = {1};
        merge(nums1, 1, nums2, 1);
        for(int i = 0; i < nums1.length; i++) {
            System.out.print(nums1[i]);
        }

    }

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
        }
        // 指针i指向第一个数组内容的末尾
        int i = m - 1;
        // 指针j指向第二个数组的末尾
        int j = n - 1;
        // 指针k指向第一个数组的末尾
        int k = m + n - 1;
        while (i >= 0 && j >= 0 && k >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
                k--;
            } else {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        while (i >= 0) {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
}
