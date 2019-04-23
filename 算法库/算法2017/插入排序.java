// 插入排序
// 每次插入的时候先将比它大的数移到后面去留出位置
// 将一个数据插入到已经排好序的有序数据中
import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] a;
	static int x;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			System.out.print(a[i]);
		}
		System.out.println();
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				// 若小于前一个数则要挪动前面的数字
				// 否则直接插入进行下一次循环
				x = a[i]; // 保存a[i]的值
				// 开始后移
				int j = 0;
				for (j = i - 1; j >= 0 && a[j] > x; j--) {
					a[j + 1] = a[j];
				}
				a[j + 1] = x;
			}
		}
		for (int i = 0; i < n; i++) {
			System.out.print(a[i]);
		}
	}
}