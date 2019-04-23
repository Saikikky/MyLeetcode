

 //求n的k个互不相交的子集
 import java.util.Scanner;

public class Main {
	// 从第一个元素开始判断是否在子集中 不在为0
	// 在为1 全部完成之后 输出
	static int n; // n个数
	static int k; // k个互不相交的子集
	static int ok = 0; // 判断是否有k个子集
	static int count = 0; // 记录子集个数  
	static int[] a;
	static int[] flag;
	
	static void DFS(int x) {
		if (x > n) { 
			// 输出
			for (int i = 1; i <= k; i++) {
			//	System.out.println("i1 = " + i);
				for (int j = 1; j <= n; j++) {
					if (flag[j] == i) {
			//			System.out.println("i2 = " + i);
						ok += i;
						j =n+1;
					}
				}
			//	System.out.println("ok = " + ok);
				
			}
			
			if (ok == ((1 + k) * k / 2)) {
//				for (int i = 1; i <= n; i++) {
//					System.out.print(flag[i]);
//				}
			
				for (int i = 1; i <= k ; i++) {
					for (int j = 1; j <= n; j++) {
						if (flag[j] == i) {
							System.out.print(a[j]);
						}
					}
					System.out.print(" ");
				}
				System.out.println();
			}
			ok = 0;
		} else {
			for (int i = 1; i <= k; i++) {
				flag[x] = i;
				DFS(x + 1);
				flag[x] = 0;
			}
		}
		
	}

    public static void main(String[] args) {
        
    	Scanner in = new Scanner(System.in);
    	n = in.nextInt();
    	k = in.nextInt();
    
    	a = new int[n + 1];
    	flag = new int[n + 1];
    	
    	for (int i = 1; i <= n; i++) {
    		a[i] = i;
    	}
    	
    	DFS(1);
    	
    }
}

