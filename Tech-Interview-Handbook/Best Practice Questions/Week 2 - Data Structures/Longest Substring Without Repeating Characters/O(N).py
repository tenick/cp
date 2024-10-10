class Solution(object):
    def lengthOfLongestSubstring(self, k):
        if len(k) < 2:
            return len(k)
        
        dic = {}
        res = 0
        r = 0
        for s in range(len(k)):
            if k[s] not in dic:
                dic[k[s]] = s
            if s > dic[k[s]] and r <= dic[k[s]]:
                r = dic[k[s]] + 1
            dic[k[s]] = s
            res = s - r + 1 if s - r + 1 > res else res
            
        return res