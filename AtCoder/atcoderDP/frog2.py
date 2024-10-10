n, K = list(map(int, input().split()))
H = list(map(int, input().split()))
dp = [None for x in range(n)]
dp[0] = 0
for i in range(n-1):
    for k in range(1, K + 1):
        if k == n:
            break
        if i + k < n:
            val = abs(H[i] - H[i+k]) + dp[i]
            dp[i+k] = val if dp[i+k] is None else val if dp[i+k] > val else dp[i+k]
print(dp[n-1])
