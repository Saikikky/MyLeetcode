//最长非降序子序列
import java.util.Scanner;

public class Main {
	
	static int n; // 数组长度
	static int[] a; // 数组
	static int[] result; // 存放结果数组
	
	static void LongestLength(int x) {
		
		int length = 1;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j < i; j++) {
				if (a[i] > a[j]) {
					int temp = result[j] + 1;
					if (temp > length) {
						length = temp;
					}
				}
			}
			result[i] = length;
			System.out.println(result[i]);
		}
	}
	public static void main(String[] args) {
	
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = new int[n + 1];
		result = new int[n + 1];
		
		for (int i = 1; i <= n; i++) {
			a[i] = in.nextInt();
		}

		LongestLength(n);
	
	}
}
