//硬币问题
import java.util.Scanner;

public class Main {
	
	static int money; // 输入总数money
	static int[] coinValue; // 保存硬币面值
	static int[] coinNum; // 保存下标为i的总数量所需要的最小硬币数
	
	
	static void FindChange(int x) {
		
		// 对每一块钱都做一次最小硬币数计算
		for (int i = 1; i <= x; i++) {
			int minCoins = i;
		
			for (int j = 1; j <= 3; j++) {
				
				if (coinValue[j] <= i && (i - coinValue[j]) >= 0) {
					int temp = 1 + coinNum[i - coinValue[j]];
					if (temp < minCoins) {
						minCoins = temp;
					}
				}
			}
			coinNum[i] = minCoins;
		}
	}
	
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		money = in.nextInt();
		
		coinValue = new int[4]; 
		for (int i = 1; i < 4; i++) {
			coinValue[i] = in.nextInt();
		}
		
		coinNum = new int[money + 1];
		
		FindChange(money);
		System.out.println(coinNum[money]);
	}
}

/*
public class Main {

	static int money; // 题目给出总数money
	static int[] coinValue; // 硬币面值
	static int[] coinsUsed; // 保存每一个面值找零所需的最小硬币数

	
	static void F(int x) {
		// 对每一块钱算其最小使用硬币数
		for (int i = 1; i <= x; i++) {
			
			// 使用最小硬币找零时，所需硬币数量最多
			int minCoins = i;
			
			// 遍历每一种面值的硬币时，看是都可以作为找零
			for (int j = 1; j <= 3; j++) {
				// 当前值的硬币小于当前i则分解问题
				if (coinValue[j] <= i) {
					int temp = coinsUsed[i - coinValue[j]];
					if (temp < minCoins) {
						minCoins = temp;
					}
				}
			}
			// 保存最小硬币数
			coinsUsed[i] = minCoins;
			
			System.out.println(coinsUsed[i]);
		}
	}
	public static void main(String[] args) {
	
		Scanner in = new Scanner(System.in);
		money = in.nextInt();
		coinValue = new int[4];
		for (int i = 1; i <= 3; i++) {
			coinValue[i] = in.nextInt();
		}
		
		coinsUsed = new int[money + 1];
		
		F(money);
		
		System.out.println(coinsUsed[money]);
	}
}

*/