from xmlrpc.client import MAXINT


t = int(input())
for _ in range(t):
    x, n = input().split()
    onset = 0

    for i in range(1, len(n)):
        same = True
        for j, k in enumerate(range(i, len(n))):
            same = same and n[j] == n[k]
        if same:
            onset = len(n) - i
            break
    
    nChars = {}
    xChars = {}
    for i in range(len(n) - onset):
        if n[i] in nChars:
            nChars[n[i]] += 1
        else:
            nChars[n[i]] = 1
            xChars[n[i]] = 0

    for c in x:
        if c in xChars:
            xChars[c] += 1
    
    reps = min([xChars[k] // nChars[k] for k in nChars])
    nhaisWhole = sum([nChars[k] for k in nChars]) * reps
    additional = 0
    full = True
    
    isPalindrome = len(n) % 2 == 1 and len(n) // 2 + 1 == onset

    for i in [len(n) - onset] if isPalindrome else range(len(n) - onset, len(n)):
        if n[i] in xChars and xChars[n[i]] - reps * nChars[n[i]] > 0:
            xChars[n[i]] -= 1
            additional += 1
        else:
            full = False
            break
    if full:
        nhaisWhole += additional

    if nhaisWhole == 0:
        print(0)
    else:
        nhaisLimit = nhaisWhole - len(n)
        
        if nhaisLimit < 0:
            print(0)
        else:
            jump = len(n) - onset
            print(nhaisLimit // jump + 1)
