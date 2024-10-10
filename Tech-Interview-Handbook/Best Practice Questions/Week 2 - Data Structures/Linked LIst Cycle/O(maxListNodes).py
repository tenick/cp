# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        if not head:
            return False
        count = 0
        while head and count < 10**4:
            head = head.next
            count += 1
            if not head:
                return False
        return True
