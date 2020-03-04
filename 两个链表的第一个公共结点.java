/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
         if (pHead1 == null || pHead2 == null) return null;
        int len1 = 0, len2 = 0;
        ListNode p1 = pHead1;
        ListNode p2 = pHead2;
        while (p1 != null) {
            len1++;
            p1 = p1.next;
        }
        while (p2 != null) {
            len2++;
            p2 = p2.next;
        }
        p1 = pHead1;
        p2 = pHead2;
        int lens = len1 - len2;

        if (lens < 0) {
            while (lens != 0) {
                lens++;
                p2 = p2.next;
            }
        } else {
            while (lens != 0) {
                lens--;
                p1 = p1.next;
            }
        }

        while (p1 != null && p2 != null) {
            if (p1 == p2) return p1;
            p1 = p1.next;
            p2 = p2.next;
        }
        return null;
    }
}