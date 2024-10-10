class Solution(object):
    def characterReplacement(self, s, v):
        j = k = 0
        maxRepStrLen = 1
        maxC = 0
        dic = {chr(x): 0 for x in range(65, 91)}
        
        while k < len(s):
            dic[s[k]] += 1
            
            maxC = dic[s[k]] if dic[s[k]] > maxC else maxC
            
            while k - j + 1 - maxC > v:
                dic[s[j]] -= 1
                j += 1
                
            maxRepStrLen = k - j + 1 if k - j + 1 > maxRepStrLen else maxRepStrLen
            k += 1
        return maxRepStrLen