
 //求子集
 //二叉树 不需要将标记改回 因为对后面几层都没有影响
import java.util.Scanner;

public class Main {
	// 从第一个元素开始判断是否在子集中 不在为0
	// 在为1 全部完成之后 输出
	static int n; // n个数
	static int[] a; // 用于存储子集
	static int[] flag; // n个数的标志位
	static int count = 0;
	static void DFS(int x) {
		if (x > n) { 
			// 输出
			
			for (int i = 1; i <= n; i++) {
				if (flag[i] == 1) {
					System.out.print(a[i]);
				}
			}
			count++;
			System.out.println();
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
    	a = new int[n + 1];
    	flag = new int[n + 1];
    	
    	for (int i = 1; i <= n; i++) {
    		a[i] = i;
    	}
    	
    	DFS(1);
    }
}
