import java.util.Iterator;
import java.util.PriorityQueue;

public class HeapSort {

    public static void main(String[] args) {
        int[] array = {1,5,3,8,6,7,3,6,9,0};
        getTopKByHeapInsertTopKElement(array, 3);

    }
    public static void getTopKByHeapInsertTopKElement(int[] array, int k) {
        // 准备一个最小堆
        PriorityQueue<Integer> heap = new PriorityQueue<>(k);
        // 始终维持一个总结点个数为k的堆：
        insertButmaintainTheHeapAtTopK(heap, array, k);

        // 得到topK
        printHeap(heap);

    }
    /**
     *  用小顶堆来获取topK：当数据量超过topK后，新产生的数据直接和heap的顶结点进行比较。
     */
    public static void insertButmaintainTheHeapAtTopK(PriorityQueue<Integer> heap, int[] array, int k) {
        for (int i = 0; i < array.length; i++) {
            if (i < k) {
                heap.add(array[i]);
            } else {
                System.out.println(heap.peek());
                if (heap.peek() != null && array[i] > heap.peek()) {
                    heap.poll();
                    heap.add(array[i]);
                }
            }
        }
    }

    public static void printHeap(PriorityQueue<Integer> heap) {
        Iterator<Integer> iterator = heap.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }


}
