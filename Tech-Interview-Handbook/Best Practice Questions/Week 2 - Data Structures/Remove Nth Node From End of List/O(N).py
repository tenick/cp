# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        head2 = head
        nodeList = []
        
        while head:
            nodeList.append(head)
            head = head.next
        
        if n == len(nodeList):
            return head2.next
        else:
            nodeToRemove = nodeList[-n]
            nodeList[-n-1].next = nodeToRemove.next
            return head2
        