// 1-n的全排列

static int n;
static int[] a;
static int[] flag;

static void DFS(int x) {
	if (x == n + 1) {
		// 输出
		for (int i = 1; i <= n; i++){
			System.out.print(a[i]);
		}
		System.out.println();
	}
	else {
		for (int i = 1; i <= n; i++) {
				if (flag[i] == 0) {
					flag[i] = 1;
					
					a[x] = i;
					DFS(x + 1);
					
					flag[i] = 0;
				}
			
		}
		
	}
}

public static void main(String[] args) {
    
	Scanner in = new Scanner(System.in);
	n = in.nextInt();
	a = new int[n + 1];
	flag = new int[n + 1];
	
	DFS(1);
}
