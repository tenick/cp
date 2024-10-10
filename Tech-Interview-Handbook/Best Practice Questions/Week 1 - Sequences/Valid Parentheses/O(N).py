class Solution(object):
    def isValid(self, s):
        stack = []
        
        closing = {')', '}', ']'}
        closing_pair = {')': '(', '}': '{', ']': '['}
        
        for c in s:
            if c not in closing:
                stack.append(c)
            elif not stack or closing_pair[c] != stack[-1]:
                return False
            else:
                stack.pop()
        return not len(stack)