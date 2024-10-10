# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    keys = [-2**31-1]
    def isValidBST(self, root):
        self.keys = [-2**31-1]
        return self.inOrder(root)
        
    def inOrder(self, root):
        if root is None:
            return True
        
        if not self.inOrder(root.left):
            return False
        b = root.val
        if self.keys[-1] >= b:
            return False
        self.keys.append(b)
        if not self.inOrder(root.right):
            return False
        
        return True