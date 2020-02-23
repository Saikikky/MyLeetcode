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