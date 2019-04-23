// 交换排序（冒泡排序）
// （改进）可以增加一个判断 若一轮下来没有变化位置的元素则表示已经排好 则直接退出
import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] a;
	
	static void bubbleSort(int[] a) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > i; j--) {
				if (a[j] < a[j - 1]) {
					int temp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = temp;
				}
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
		
		bubbleSort(a);
		
		for (int i = 0; i < n; i++) {
			System.out.print(a[i]);
		}
		System.out.println();
	}
}