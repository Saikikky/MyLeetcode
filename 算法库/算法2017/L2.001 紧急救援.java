/*输入格式：

输入第一行给出4个正整数N、M、S、D，其中N（2<=N<=500）是城市的个数，顺便假设城市的编号为0~(N-1)；M是快速道路的条数；S是出发地的城市编号；D是目的地的城市编号。第二行给出N个正整数，其中第i个数是第i个城市的救援队的数目，数字间以空格分隔。随后的M行中，每行给出一条快速道路的信息，分别是：城市1、城市2、快速道路的长度，中间用空格分开，数字均为整数且不超过500。输入保证救援可行且最优解唯一。

输出格式：

第一行输出不同的最短路径的条数和能够召集的最多的救援队数量。第二行输出从S到D的路径中经过的城市编号。数字间以空格分隔，输出首尾不能有多余空格。

输入样例：
4 5 0 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2
输出样例：
2 60
0 1 3
*/
import java.util.Scanner;

public class Main {
	
	static int N; // 城市个数
	static int M; // 快速道路的条数
	static int S; // 出发地编号
	static int D; // 目的城市编号
	
	static int r[]; // 每个城市拥有的救援队数量               顶点的权
	static int a[][]; // 保存快速通道信息
	static int t[]; // 暂时保存通道信息 用于存储通道	
	
	static int min = 99999999; // 保存最短路径长度 
	static int rescue; // 能够召集的救援队的数量
	static int s; // 计算最短路径
	static int d; // 计算救援队数量
	
	static int count; // 不同最短路径的条数
	
	static int[] flag; 
	static int h = 1;
	static int[] temp;
	
	static void DFS(int x, int y) { // x为起始城市 y为目的地
		
		if (x == y) {
			
		
			// 判断是否为最短路径
			if (s < min) {
				count=1;
				min = s;
				rescue = d;
				for (int i = 0; i < N; i++) {
					temp[i] = flag[i];
				}
			} else if (s == min) {
				count++;
				if (rescue < d) {
					rescue = d;
					for (int i = 0; i < N; i++) {
						temp[i] = flag[i];
					}
				}
			}
		} else {
			for (int i = 0; i < N; i++) {
				if (a[x][i] != 0 && flag[i] == 0) {								
					flag[i] = ++h;				
					// 两目的地之间有快速通道								
					s += a[x][i];
					d += r[i];
					
					
					DFS(i, D);
					
					h--;
					flag[i] = 0;
					s -= a[x][i];
					d -= r[i];
					
					
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = in.nextInt();
		M = in.nextInt();
		S = in.nextInt();
		D = in.nextInt();
		r = new int[N];
		for (int i = 0; i < N; i++) {
			r[i] = in.nextInt();
		}
		t = new int[3];
		a = new int[N][N];
		flag = new int[N];
		flag[S] = h;
		temp = new int[N];
		for (int j = 0; j < M; j++) {
			for (int i = 0; i < 3; i++) {
				t[i] = in.nextInt();
			}
			a[t[0]][t[1]] = t[2];
			a[t[1]][t[0]] = t[2];
		}
	
		d = r[S];
		// 开始回溯
		DFS(S, D);

		System.out.println(count + " " + rescue);
		int w = 0;
		for (int i = 0; i < N; i++) {
			if (temp[i] != 0) {
				w++;
			}
		}
		int f = w;
		for (int j = 1; j <= w; j++){
			 for (int i = 0; i < N; i++) {
				if (temp[i] == j) {
					System.out.print(i);
					if (f > 1) {
						System.out.print(" ");
						f--;
					}
				}
			}
			
		
		}
		
	}
}