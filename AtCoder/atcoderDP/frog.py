n = int(input())
H = list(map(int, input().split()))
dp = [None for x in range(n)]
dp[0] = 0
for i in range(n-1):
    if i + 1 < n:
        val = abs(H[i] - H[i+1]) + dp[i]
        dp[i+1] = val if dp[i+1] is None else val if dp[i+1] > val else dp[i+1]
    if i + 2 < n:
        val = abs(H[i] - H[i+2]) + dp[i]
        dp[i+2] = val if dp[i+2] is None else val if dp[i+2] > val else dp[i+2]
print(dp[n-1])
