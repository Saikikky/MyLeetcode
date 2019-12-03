/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode h = head;
        ListNode l1 = new ListNode(-1);
        ListNode h1 = l1;
        ListNode l2 = new ListNode(-1);
        ListNode h2 = l2;

        while (h != null) {
            if (h.val < x) {
                h1.next = h;
                // h = h.next;
                h1 = h1.next;
                // h1.next = null;

            } else {
                h2.next = h;
                // h = h.next;
                h2 = h2.next;
                // h2.next = null;

            }
            h = h.next;
        }
        h2.next = null;
        h1.next = l2.next;
        return l1.next;
    }
}