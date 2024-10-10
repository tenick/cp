def maxReverse(a, b):
    dp = [[0 for _ in range(len(a))] for _ in range(len(a))]

    for i in range(len(a)):
        for j in range(i + 1):
            s = j
            e = j + len(a) - i - 1

            L1 = a[s] == b[s]
            L2 = a[e] == b[e]
            oppL1 = a[s] == b[e]
            oppL2 = a[e] == b[s]

            if s - 1 >= 0 and e + 1 < len(a) and e - s + 2 < len(a):
                update = max(0, dp[e - s + 2][s - 1] + oppL1 + oppL2 - (L1 + L2))
                dp[e - s][s] = update
            else:
                newMemo = max(0, oppL1 + oppL2 - (L1 + L2))
                dp[e - s][s] = newMemo
    
    maxReverseVal = 0
    for i in range(1 + (len(a) >= 2)):
        for j in range(len(a)):
            maxReverseVal = max(maxReverseVal, dp[i][j])

    for i in range(len(a)):
        if a[i] == b[i]:
            maxReverseVal += 1
    
    return maxReverseVal

t = int(input())
for _ in range(t):
    a, b = input(), input()
    print(maxReverse(a, b))
