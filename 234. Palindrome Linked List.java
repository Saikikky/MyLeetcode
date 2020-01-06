/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        // 将后半段链表逆置 然后一起对比每一个是不是一样的
        if (head == null) return true;
        ListNode cur = null, tmp = head;
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // 逆置
        while (slow != null) {
            ListNode newNode = new ListNode(slow.val);
            if (cur == null) {
                cur = newNode;
            } else {
                newNode.next = cur;
                cur = newNode;
            }
            slow = slow.next;
        }
        while (cur != null) {
            if (cur.val != head.val) return false;
            cur = cur.next;
            head = head.next;
        }
        return true;
    }
}