/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null) return null;
        ListNode listNode = new ListNode(0);
        listNode.next = head;

        ListNode s1 =  listNode;
        while (s1.next != null && s1.next.next != null) {
            ListNode s2 = s1.next;
            s1.next = s2.next;
            s2.next = s2.next.next;
            s1.next.next = s2;
            s1 = s1.next.next;
        }

        return listNode.next;
    }
}