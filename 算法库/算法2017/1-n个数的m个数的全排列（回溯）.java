// 1-n中的m个全排列
	static int n; // n个数
	static int m; // m个数的全排列
	static int[] a; // 用于输出m个数的全排列
	static int[] flag; // n个数的标志位
	
	static void DFS(int x) {
		if (x == m + 1) {
			// 输出
			for (int i = 1; i <= m; i++){
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
    	m = in.nextInt();
    	
    	flag = new int[n + 1];
    	a = new int[m + 1];
    	
    	
    	DFS(1);
    }

    /*
    bool isPrime(int num)  
{  
    if (num == 2 || num == 3)  
    {  
        return true;  
    }  
    if (num % 6 != 1 && num % 6 != 5)  
    {  
        return false;  
    }  
    for (int i = 5; i*i <= num; i += 6)  
    {  
        if (num % i == 0 || num % (i+2) == 0)  
        {  
            return false;  
        }  
    }  
    return true;  
}  
    */