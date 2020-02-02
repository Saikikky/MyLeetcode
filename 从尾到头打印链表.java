import java.util.ArrayList;
import java.util.Stack;

class ListNode {
    int val;
    ListNode next = null;
    ListNode(int val) {
        this.val = val;
    }
}

/**
 * 用栈
 */
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        Stack<Integer> stack = new Stack<>();
        ArrayList<Integer> list = new ArrayList<>();

        while (listNode != null) {
            stack.push(listNode.val);
            listNode = listNode.next;
        }

        while(!stack.empty()) {
            Integer number = stack.pop();
            list.add(number);
        }
        return list;
    }

}

    /**
     * 用递归  栈跟递归很相似
     * 但代码实现中list每次会重新更新导致list长度始终唯一
     * 设为全局之后测试用例不会每次重新运行代码 故每次有残留
     * 暂时未解决
     * @param listNode
     */
    public static void printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> list = new ArrayList<>();
        if (listNode != null) {
            if (listNode.next != null) {
                printListFromTailToHead(listNode.next);
            }
            System.out.println(listNode.val);
        }
    }

// 更新递归方法
ArrayList<Integer> list = new ArrayList<>();
public void printListFromTailToHead(ListNode listNode) {
    if (listNode != null) {
        printListFromTailToHead(listNode.next);
        list.add(listNode.val);
    }
}