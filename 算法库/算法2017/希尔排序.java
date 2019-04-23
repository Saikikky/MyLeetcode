// 希尔排序 (直接插入排序的改进)
import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] a;
	static int x;
	static int lim;
	
	static void shellInsertSort(int d) {
		System.out.println();
		for (int i = d; i < n; i++) {
			if (a[i] < a[i - d]) {
				// 若第i个元素大于第i-d个元素 直接跳过
		
				int j = i - d;
				int x = a[i]; // 保留a[i] 存储待排序元素
				System.out.println(x);
				a[i] = a[i - d]; // 后移一个元素
				while (x < a[j]) { // 分组排序
				
					a[j + d] = a[j];
					j -= d; // 元素后移
				}
				a[j + d] = x; // 插入
				for (int m = 0; m < n; m++) {
					System.out.print(a[m]);
				}
				System.out.println();
			}
		}
	}
	
	static void shellSort() {
		
		lim = n / 2; // 首先以一半为增量进行排序
		
		while (lim >= 1) {
		
			shellInsertSort(lim);
			lim = lim / 2;
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
	
		
		shellSort();
		
		for (int i = 0; i < n; i++) {
			System.out.print(a[i]);
		}
		System.out.println();
	}
}