/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode fakeHead = new ListNode(-1);
        fakeHead.next = head;
        ListNode p1 = fakeHead, p2 = head;
        while (p2 != null) {
            if (p2.val == val) {
                p2 = p2.next;
                p1.next = p2;
            } else {
                p1 = p2;
                p2 = p2.next;
            }
        }
        return fakeHead.next;
    }
}