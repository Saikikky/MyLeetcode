//打印沙漏
import java.util.Scanner;

public class Main {
	static int n;
	static char c;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		String c = in.next();
		
		int temp = n / 2 + 1;
		int sum = 0;
		int i = 0;
		int count = 0;
		int s = 0;
	
		for (i = 1; sum < temp; i = i + 2) {
			
			if (sum + i > temp) break;
			count++;
			sum += i;
			
		}
		
		
		i = i - 2;
		sum -= i;
		
		for (int j = 1; j <= count; j++) {
			if (j > 1) {
				for (int k = 1; k <= j - 1; k++) {
					System.out.print(" ");
				}
			}
			for (int k = 1; k <= i; k++) {
				System.out.print(c);
			}
			s += i;
			System.out.println();
			i = i - 2;
		
		}
		
		s = (s - 1) * 2 + 1;
		i = i + 4;
	
		for (int j = count; j > 1; j--) {
			if (j > 1) {
				for (int k = 1; k < j - 1; k++) {
					System.out.print(" ");
				}
			}
			for (int k = 1; k <= i; k++) {
				System.out.print(c);
			}
			System.out.println();
			i = i + 2;
			
		}
		System.out.println(n - s);
	}

		
}