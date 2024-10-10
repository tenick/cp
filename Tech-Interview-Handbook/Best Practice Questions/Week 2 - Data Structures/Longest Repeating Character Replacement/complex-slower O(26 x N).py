class Solution(object):
    def characterReplacement(self, s, v):
        # build dict of letter-list
        dic = {}
        count = 0
        for c in s:
            if c not in dic:
                dic[c] = [-count]
            for k in dic:
                if k == c:
                    if dic[k][-1] < 0:
                        dic[k].append(1)
                    else:
                        dic[k][-1] += 1
                else:
                    if dic[k][-1] < 0:
                        dic[k][-1] -= 1
                    else:
                        dic[k].append(-1)
            count += 1
        
        # sliding window for each list for each letter, save the max
        maxSubstrLen = 1
        for k in dic:
            lst = dic[k] # guaranteed to have at least 2 elements
            l = 1 if lst[0] < 0 else 0
            r = l
            
            currSubstrLen = 0
            currK = v
            
            while True:
                if lst[r] >= 0: # positive
                    currSubstrLen += lst[r]
                    if r >= len(lst) - 2:
                        substitutableLettersAmt = 0
                        if l - 1 >= 0:
                            substitutableLettersAmt += abs(lst[l-1])
                        if r + 1 < len(lst):
                            substitutableLettersAmt += abs(lst[r+1])
                        if substitutableLettersAmt >= currK:
                            currSubstrLen += currK
                        else:
                            currSubstrLen += substitutableLettersAmt
                            
                        if currSubstrLen > maxSubstrLen:
                            maxSubstrLen = currSubstrLen
                        break
                    else:
                        r += 1
                    
                    if currSubstrLen > maxSubstrLen:
                            maxSubstrLen = currSubstrLen
                else: # negative
                    if abs(lst[r]) > v:
                        currSubstrLen += currK
                        
                        if currSubstrLen > maxSubstrLen:
                            maxSubstrLen = currSubstrLen
                            
                        r += 1
                        l = r
                        currK = v
                        currSubstrLen = 0
                    else:
                        if currK + lst[r] >= 0:
                            currK += lst[r]
                            currSubstrLen -= lst[r]
                            
                            if currSubstrLen > maxSubstrLen:
                                maxSubstrLen = currSubstrLen
                            
                            r += 1
                        else:
                            if currSubstrLen + currK > maxSubstrLen:
                                maxSubstrLen = currSubstrLen + currK
                            
                            currSubstrLen -= lst[l]
                            l += 1
                            currK -= lst[l]
                            currSubstrLen += lst[l]
                            l += 1
        return maxSubstrLen
