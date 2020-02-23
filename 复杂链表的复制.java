import java.util.HashMap;
/*
public class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
*/

/**
新旧链表合成一个链表然后再分解
**/
public class Solution {
    public RandomListNode Clone(RandomListNode pHead)
    {
        if (pHead == null) return null;
        RandomListNode tmp = pHead;
        RandomListNode nextNode = null;
        while (tmp != null) {
            RandomListNode newNode = new RandomListNode(tmp.label);
            nextNode = tmp.next;
            tmp.next = newNode;
            newNode.next = nextNode;
            tmp = nextNode;
        }

        tmp = pHead;
        while (tmp != null) {
            if (tmp.random != null) {
                tmp.next.random = tmp.random.next;
            }
            tmp = tmp.next.next;
        }
        tmp = pHead;
        RandomListNode newList = tmp.next;
        while (tmp != null) {
            RandomListNode cloneNode = tmp.next;
            tmp.next = cloneNode.next;
            if (cloneNode.next == null) cloneNode.next = null;
            else cloneNode.next = cloneNode.next.next;
            tmp = tmp.next;
        }
        return newList;
    }
}




public class Solution {
    public RandomListNode Clone(RandomListNode pHead)
    {
        if (pHead == null) return null;
        HashMap<RandomListNode, RandomListNode> relation = new HashMap<>();
        RandomListNode head = new RandomListNode(pHead.label);
        relation.put(pHead, head);
        RandomListNode tmp = pHead;
        while (tmp != null) {
            if (tmp.next != null) {
                if (!relation.containsKey(tmp.next)) {
                    RandomListNode newNode = new RandomListNode(tmp.next.label);
                    relation.put(tmp.next, newNode);
                }
                relation.get(tmp).next = relation.get(tmp.next);
            }
            if (tmp.random != null) {
                if (!relation.containsKey(tmp.random)) {
                    RandomListNode newNode = new RandomListNode(tmp.random.label);
                    relation.put(tmp.random, newNode);
                }
                relation.get(tmp).random = relation.get(tmp.random);
            }
            tmp = tmp.next;
        }

        return head;
    }
}