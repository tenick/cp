# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        while head:
            if head.val is None:
                return True
            head.val = None
            head = head.next
        return False
