N, W = list(map(int, input().split()))
I = []
for i in range(N):
    I.append(list(map(int, input().split())))
dp = [[0 for x in range(N)] for y in range(W+1)]
for n in range(N):
    for w in range(W+1):
        currw = I[n][0]
        val = 0
        if w >= currw:
            val = I[n][1]
            if w - currw >= 0 and n - 1 >= 0:
                val += dp[w - currw][n - 1]
            if n - 1 >= 0:
                val = val if dp[w][n - 1] < val else dp[w][n - 1]
        else:
            if n - 1 >= 0:
                val = dp[w][n - 1]
        dp[w][n] = val
print(dp[W][N-1])