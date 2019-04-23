// 归并排序
import java.util.Scanner;

public class Main {
	
	static int n;
	static int[] a;
	static int[] b;
	
	static void MergeSort(int[] a, int from, int to) {
		int tag, i, j;
		if (from < to) {
			int pos = (to + from) / 2;
			
			MergeSort(a, from, pos);
			MergeSort(a, pos + 1, to);
			
			if (from <= pos) {
				for (tag = from, i = from, j = pos + 1; i <= pos && j <= to;) {
					if (a[i] < a[j]) {
						b[tag++] = a[i++];
					} else if (a[i] > a[j]) {
						b[tag++] = a[j++];
					} else if (a[i] == a[j]) {
						b[tag++] = a[i++];
						b[tag++] = a[j++];
					}
				}
				while (i <= pos) b[tag++] = a[i++];
				while (j <= to) b[tag++] = a[j++];
				for (int m = from; m <= to; m++) {
					a[m] = b[m];
				}
				
			}
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		MergeSort(a, 0, n - 1);
		
		for (int i = 0; i < n; i++) {
			System.out.print(b[i]);
		}
		System.out.println();
	}
}

