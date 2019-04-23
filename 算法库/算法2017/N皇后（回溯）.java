
//N皇后
import java.util.Scanner;

public class Main {
	
	static int[][] queen;
	static int n;
	static int count;
	static boolean can_place(int x, int y) {  // 第x行y列
		for (int i = 1; i <= n; i++) {
			if (queen[i][y] == 1) return false;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (Math.abs(x - i) == Math.abs(y - j)) {
					if (queen[i][j] == 1) return false;
				}
			}
		}
		return true;
	}
	
	static void DFS(int x) { // 第x行
		if (x >= n + 1) { 
			// 输出
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					System.out.print(queen[i][j]);
				}
				System.out.println();
			}
			count++;
			System.out.println();
		} else {
			for (int i = 1; i <= n; i++) {
				if (queen[x][i] == 0 && can_place(x, i)) { // 第i列暂时没有放皇后
					queen[x][i] = 1;
					
					DFS(x + 1);
					
					queen[x][i] = 0;
				}
			}
		}
	}
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		queen = new int[n + 1][n + 1];
		
		DFS(1);
		System.out.println(count);
	}
}

