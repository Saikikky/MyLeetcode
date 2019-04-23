// 交换排序（快速排序）
import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] a;
	
	static void quickSort(int[] a, int low, int high) {
		if (low < high) {
			int i = low, j = high, x = a[low]; // x找基数
			while (i < j) {
				while (i < j && a[j] >= x) { // 从右向左找第一个小于x的数
					j--;
				}
				if (i < j) {
					a[i++] = a[j]; // 即a[i] = a[j]; i++;
				}
				while (i < j && a[i] < x) { // 从左向右找第一个大于等x的数
					i++;
				}
				if (i < j) {
					a[j--] = a[i];
				}
			}
			a[i] = x;
			quickSort(a, low, i - 1); // 递归调用
			quickSort(a, i + 1, high);
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		quickSort(a, 0, n - 1);
		
		for (int i = 0; i < n; i++) {
			System.out.print(a[i]);
		}
		System.out.println();
	}
}
