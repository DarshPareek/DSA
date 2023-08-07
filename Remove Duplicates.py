class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseList(self, head):
        dhead = head
        l = 0
        while head is not None:
            l += 1
            head = head.next
        c = l//2
        head = dhead
        for i in range(c):
            head = head.next
        return head


def printll(head):
    while head is not None:
        print(head.val)
        head = head.next


l11 = ListNode(1)
l12 = ListNode(2)
l13 = ListNode(6)
l14 = ListNode(3)
l15 = ListNode(4)
l16 = ListNode(5)
l11.next = l12
l12.next = l13
l13.next = l14
l14.next = l15
l15.next = l16
# l11 = ListNode(1)
# l12 = ListNode(2)
# l13 = ListNode(3)
# l14 = ListNode(4)
# l15 = ListNode(5)
# l16 = ListNode(6)
# l11.next = l12
# l12.next = l13
# l13.next = l14
# l14.next = l15
# l15.next = l16
# printll(l11)
sol = Solution()
print(sol.reverseList(l11).val)
