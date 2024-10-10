class Solution(object):
    def minWindow(self, s, t):
        # init char dict
        chars = {}
        for c in t:
            if c in chars:
                chars[c][1] += 1
            else:
                chars[c] = [0, 1]
        
        l = r = 0
        iLst = []
        charSet = set()
        minWndw = len(s) + 1
        minWndwIndices = [0, len(s) + 1]
        
        for i in range(len(s)):
            if s[i] in chars:
                iLst.append(i)
                chars[s[i]][0] += 1
                l = 0
                r = i
                if chars[s[i]][0] == chars[s[i]][1]:
                    charSet.add(s[i])
                minWndwIndices = [i, i]
                break
        
        for i in range(r + 1, len(s)):
            if s[i] in chars:
                iLst.append(i)
                
                chars[s[i]][0] += 1
                
                if chars[s[i]][0] == chars[s[i]][1]:
                    charSet.add(s[i])
                    
                
                while chars[s[iLst[l]]][0] > chars[s[iLst[l]]][1]:
                    chars[s[iLst[l]]][0] -= 1
                    l += 1
                
                if len(charSet) == len(chars) and i - iLst[l] + 1 < minWndw:
                    minWndw = i - iLst[l] + 1
                    minWndwIndices = [iLst[l], i]
                    
        return s[minWndwIndices[0]:minWndwIndices[1] + 1] if len(charSet) == len(chars) else ""
