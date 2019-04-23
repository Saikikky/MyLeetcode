
// 连续因子
import java.util.Scanner;

public class Main {
	
	static int n, m; // 需要求连续因子的数
	static int[] value; // 保存每一个数的最长连续因子的第一个数
	static int[] size; // 保存每一个数的最长连续因子的长度
	
	static void F(int n) {
		int length = 0;
		int limit = (int) Math.sqrt(n);
		System.out.println("limit = " + limit);
		int i = 0;
		if (n % 2 == 0) { //n是偶数才有可能
			System.out.println("come in");
			for (i = 4; i <= limit; i++) { // 从没有初始化8开始算
				System.out.println("i = " + i);
				for (int j = 2; j <= limit / 2; j++) {
					System.out.println("j = " + j);
					int temp1 = i*2 / j; // 商
					System.out.println("temp1 = " + temp1);
					int temp2 = i*2 % j; // 余数
					System.out.println("temp2 = " + temp2);
					if (j == temp1 - 1) {
						length = 2;
						size[i] = 2;
						value[i] = j;
						System.out.println(size[i]);
						break;
					} else {
						if (temp1 % 2 == 0) {
							if (temp2 == 0) {
								// 判断j是否小于最小数或者大于最大数
								length = size[temp1 / 2];
								System.out.println("length = " + length);
								System.out.println("value = " + value[temp1 / 2]);
								if (j == value[temp1 / 2] - 1) {
									value[i] = j;
									size[i] = length + 1;
									System.out.println(size[i]);
									break;
								} else if (j == value[temp1 / 2] + size[temp1 / 2]) {
									size[i] = length + 1;
									System.out.println(size[i]);
									break;
								}
							}
						}
					}
				}
			}
		}
		
	
	}
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = (int) Math.sqrt(n);
		
		value = new int[n + 1];
		
		value[3] = 2; 
		value[6] = 2;
		
		size = new int[n + 1];
		size[1] = 0; // 2
		size[2] = 0; // 4
		size[3] = 2; // 6 = 2 * 3
		size[6] = 3;
		
		F(n);
	}


}
