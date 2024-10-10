# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        currNode = None
        while head:
            print(head.val)
            next_head = head.next
            head.next = currNode
            currNode = head
            head = next_head
        return currNode
    
    def printListNode(self, listNode):
        while listNode:
            print(listNode.val)
            listNode = listNode.next
        print("done")
            