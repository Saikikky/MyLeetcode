// 动态规划解扑克问题
// 一副扑克牌出去大小王之后 任取k张牌 不计花色 共有多少种取法
import java.util.Scanner;

public class Main {
	
	static int n; // 共n种牌
	static int k; // 取k张牌
	static int[][] a; // 存储
	
	static int f(int n, int k) {
		if (k < 0 || k > 4*n) return 0;
		if (a[n][k] != 0) return a[n][k];
		else if (k == 0 || k == 4*n) return a[n][k] = 1;
		else return a[n][k] = f(n - 1, k - 1) +
				f(n - 1, k - 2) +
				f(n - 1, k - 3) +
				f(n - 1, k - 4) +
				f(n - 1, k);

	}
	
	public static void main (String[] args) { 
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		k = in.nextInt();
		a = new int[100][100];
		
		System.out.println(f(13, 13));
	}
}