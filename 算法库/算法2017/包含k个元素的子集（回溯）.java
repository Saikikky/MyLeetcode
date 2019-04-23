//求n的包含k个元素的子集
 import java.util.Scanner;

public class Main {
	// 从第一个元素开始判断是否在子集中 不在为0
	// 在为1 全部完成之后 输出
	static int n; // n个数
	static int k;
	static int sum = 0;
	static int[] a; // 用于存储子集
	static int[] flag; // n个数的标志位
	static int count = 0;
	static void DFS(int x) {
		if (x > n) { 
			// 输出
			for (int i = 1; i <= n; i++) {
				if (flag[i] == 1) sum++;
			}
			if (sum == k) {
				for (int i = 1; i <= n; i++) {
					if (flag[i] == 1) {
						System.out.print(a[i]);
					}
				}
				
				System.out.println();
			}
			sum = 0;
		} else {
			for (int i = 0; i < 2; i++) {
				flag[x] = i;
				DFS(x + 1);
			}
		}
		
	}

    public static void main(String[] args) {
        
    	Scanner in = new Scanner(System.in);
    	n = in.nextInt();
    	k = in.nextInt();
    	System.out.println(n);
    	System.out.println(k);
    	a = new int[n + 1];
    	flag = new int[n + 1];
    	
    	for (int i = 1; i <= n; i++) {
    		a[i] = i;
    	}
    	
    	DFS(1);
    	System.out.println("end");
    }
}
