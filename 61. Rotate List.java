/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0) return head;
        ListNode listNode3 = new ListNode(-2);
        ListNode listNode1 = new ListNode(-1);
        listNode3.next = listNode1;
        listNode1.next = head;
        ListNode listNode2 = head;
        // 用于查找倒数第k个节点
        ListNode test1 = listNode1;
        ListNode test2 = listNode1;
        ListNode test3 = listNode3;
        int s = 0;
        int kth = k;
        int length = 0;
        while (listNode2 != null) {
            length++;
            listNode2 = listNode2.next;
        }
        if (k == length) return head;
        if (k > length) kth = k % length;
        if (kth == 0) return head;
        while (s < kth) {
            test1 = test1.next;
            s++;
        }


        while (test1 != null) {
            test1 = test1.next;
            test2 = test2.next;
            test3 = test3.next;
        }

        test3.next = null;
        ListNode result = test2;
        while (result.next != null) {
            result = result.next;
        }
        result.next = listNode1.next;

        return test2;
    }
}