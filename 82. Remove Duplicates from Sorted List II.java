/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode head1 = new ListNode(-1);
        head1.next = head;
        ListNode pre;
        ListNode cur = head1;

        while (cur != null) {
            pre = cur;
            cur = cur.next;
            while (cur != null && cur.next != null && cur.val == cur.next.val) {
                int temp = cur.val;
                while (cur != null && cur.val == temp) {
                    cur = cur.next;
                }
                pre.next = cur;
            }

        }
        return head1.next;
    }
}