/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null) {
            return null;
        }
        int k = 1;
        ListNode fakeHead = new ListNode(-1);
        fakeHead.next = head;
        ListNode cur = fakeHead;
        while (k < m) {
            cur = cur.next;
            k++;
        }
        ListNode first = cur;
        ListNode last  = cur.next;
        ListNode index = null;
        cur = cur.next;
        ListNode nex;
        while (k <= n) {
            nex = cur.next;
            cur.next = index;
            index = cur;
            cur = nex;
            k++;
        }
        first.next = index;
        last.next = cur;
        return fakeHead.next;
    }
}