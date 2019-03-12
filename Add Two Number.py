# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
            :type l1: ListNode
            :type l2: ListNode
            :rtype: ListNode
            """
        def add(l):
            num = 0
            while l != None:
                num *= 10
                num += l.val
                l = l.next
            
            return num
        
        
        s = add(l1) + add(l2)
        
        l = ListNode(s % 10)
        
        s = s / 10;
        p = l;
        while s != 0:
            t = ListNode(s % 10)
            t.next = None
            p.next = t
            p = t
            s = s/ 10
        
        return l
