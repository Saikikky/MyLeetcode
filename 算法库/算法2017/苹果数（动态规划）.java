
import java.util.Scanner;

public class Main {
	
	static int n, m;
	static int[][] apple;
	static int[][] s; // 保存在该位置可以取得的最多苹果数
	
	static int Max(int x, int y) {
		if (x > y) return x;
		else return y;
	}
	
	static void CollectApple(int x, int y) {
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j > 0) {
					temp1 = s[i][j - 1];
				} else if (i > 0) { 
					temp2 = s[i - 1][j];
				} 
			
				s[i][j] = apple[i][j] + Max(temp1, temp2);
				temp1 = temp2 = 0;
			}
		}
		System.out.println(s[n - 1][m - 1]);
	}
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		
		apple = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				apple[i][j] = in.nextInt();
			}
		}
		s = new int[n][m];
		
		CollectApple(n, m);
	}
}