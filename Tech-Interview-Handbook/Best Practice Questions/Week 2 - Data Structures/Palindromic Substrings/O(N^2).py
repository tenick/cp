class Solution(object):
    def countSubstrings(self, s):
        l = r = 0
        count = 0
        
        for i in range(len(s)):
            count += 1
            l = r = i
            l -= 1
            r += 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1
        
        for i in range(len(s)-1):
            l = i
            r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1
        
        return count
        