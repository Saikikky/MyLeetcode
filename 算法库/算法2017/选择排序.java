// 选择排序（简单选择排序）
// 可以通过每次循环找到最大值和最小值 就可以少一半的循环时间
import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] a;
	
	static void selectionSort(int[] a) {
		for (int i = 0; i < n; i++) {
			int k = i;
			for (int j = i + 1; j < n; j++) {
				if (a[k] > a[j]) k = j;
			}
			if (k != i) {
				int temp = a[i];
				a[i] = a[k];
				a[k] = temp;
			}
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		selectionSort(a);
		
		for (int i = 0; i < n; i++) {
			System.out.print(a[i]);
		}
		System.out.println();
	}
}
