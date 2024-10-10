N, W = list(map(int, input().split()))
I = [[0, 0]]
max_v = 0

for i in range(N):
    w, v = list(map(int, input().split()))
    I.append([w, v])
    max_v += v
max_p = 0
dp = [[None for x in range(max_v + 1)] for y in range(N + 1)]
dp[0][0] = 0
for i in range(N+1):
    for j in range(max_v+1):
        if i - 1 >= 0:
            if dp[i-1][j] != None:
                dp[i][j] = dp[i-1][j]
            if j - I[i][1] >= 0:
                if dp[i-1][j-I[i][1]] != None:
                    if I[i][1] + ((j - I[i][1]) * bool(dp[i-1][j-I[i][1]])) == j:
                        ans = I[i][0] + dp[i-1][j-I[i][1]]
                        if dp[i][j] != None:
                            if ans < dp[i][j]:
                                dp[i][j] = ans
                        else:
                            dp[i][j] = ans

for i in range(N+1):
    for j in range(max_v+1):
        if dp[i][j] != None:
            if dp[i][j] <= W:
                if j > max_p:
                    max_p = j
print(max_p)
   

