# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    """Leet Code Soln"""

    def add_two_numbers(self, l1, l2):
        """SOLn Function"""
        lis1 = []
        lis2 = []
        while l1 is not None:
            lis1.append(str(l1.val))
            l1 = l1.next
        while l2 is not None:
            lis2.append(str(l2.val))
            l2 = l2.next
        n1 = "".join(lis1[::-1])
        n2 = "".join(lis2[::-1])
        res = str(int(n1)+int(n2))
        l = []
        for i in res[::-1]:
            l.append(ListNode(int(i)))
        for i in range(len(l)-1):
            l[i].next = l[i+1]
        return l[0]
