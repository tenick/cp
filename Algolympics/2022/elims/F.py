import sys
sys.setrecursionlimit(1500)

def maxReverse(s, e):
    if (s, e) in memo:
        return memo[(s, e)]
    if s > e:
        return 0
    if s == e:
        return int(a[s] == b[e])
    
    s1 = a[s] == b[s]
    e1 = a[e] == b[e]
    if s1 or e1:
        memo[(s, e)] = s1 + e1 + maxReverse(s + s1, e - e1)
        return memo[(s, e)] 
    else:
        length = e - s + 1
        for i in range(length):
            if a[s + i] != b[e - i]:
                length -= 1
        if length == e - s + 1:
            memo[(s, e)] = length
            return memo[(s, e)]
        
        memo[(s, e)] = max(length, maxReverse(s, e - 1), maxReverse(s + 1, e))
        return memo[(s, e)]
    
t = int(input())
for _ in range(t):
    a, b = input(), input()
    memo = {}
    print(maxReverse(0, len(a) - 1))
