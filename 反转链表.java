class ListNode {
    int val;
    ListNode next = null;
    ListNode(int val) {
        this.val = val;
    }
}

public class Solution {

    public static ListNode ReverseList(ListNode head) {
        if (head == null) {
            return head;
        }

        // 反转后的链表头结点
        ListNode reverseHead = null;
        // 当前结点的前一个结点
        ListNode pre = null;
        // 当前结点
        ListNode now = head;
        // 当前结点的下一结点 防止链表断裂
        ListNode next = null;

        while (now != null) {
            // 保存下一个结点
            next = now.next;

            // 当前结点是最后一个结点
            if (next == null) {
                reverseHead = now;
            }

            // 当前结点的next指向前一个结点
            now.next = pre;

            // 结点后移
            pre = now;
            now = next;

        }
        return reverseHead;
    }

    public static void main(String[] args) {

        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;

        ListNode node = ReverseList(node1);
        while (node.next!=null) {
            System.out.println(node.val);
            node = node.next;
        }

        System.out.println(node.val);
    }

}