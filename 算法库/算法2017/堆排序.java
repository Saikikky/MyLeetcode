import java.util.Scanner;

// 堆排序
public class Main {
	
	static int n;
	static int a[];
	static int halfSize;
	
	static void Swap(int[] a, int x, int y) {
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
	
	static void Max_Heapify(int[] a, int i, int size) {
		int lchild = 2*i; // i的左孩子节点序号
		int rchild = 2*i + 1; // i的右孩子节点序号
		int temp = i; // 临时变量
		if (i < n / 2) { // 若不是叶子节点则不用调整
			if (lchild <= size && a[lchild] > a[temp]) {
				temp = lchild;
			}
			if (rchild <= size && a[rchild] > a[temp]) {
				temp = rchild;
			}
			if (temp != i) {
				Swap(a, i, temp);
				Max_Heapify(a, temp, size); // 避免调整之后的以temp为父节点的子树可能会违反最大堆的原则
			}
		}
	}
	
	static void Build_Max_Heap(int[] a, int size) { // 建立堆

		for (int i = size / 2; i >= 1; i--) { // 非叶子结点的最大序号值是n/2
			Max_Heapify(a, i, size);
		}
		
	}
	
	static void HeapSort(int[] a, int size) {
		Build_Max_Heap(a, size); // 创建最大堆
		for (int i = size; i >= 1; i--) {
			// 数组中的最大元素总在根节点a[1]中 
			// 使其与a[n]互换 将其放入应在的位置 并进行下一轮堆排序
			// 交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
			Swap(a, 1, i);
		//	halfSize = halfSize - 1;
			// 将余下元素重新建立为最大堆
			Max_Heapify(a, 1, i - 1);
		}
	}
	
	

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		halfSize = n;
		
		a = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = in.nextInt();
		}
		
		HeapSort(a, n);
		
		for (int i = 1; i <= n; i++) {
			System.out.print(a[i]);
		}
		System.out.println();
	}
	
}