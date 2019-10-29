/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode test = new ListNode(0);
        test.next = head;
        ListNode listNode1 = test;
        ListNode listNode2 = test;
        int k = 0;
        while (k <= n) {
            listNode1 = listNode1.next;
            k++;
        }
        while (listNode1 != null) {
            listNode1 = listNode1.next;
            listNode2 = listNode2.next;
        }
        listNode2.next = listNode2.next.next;

        return test.next;
    }
}