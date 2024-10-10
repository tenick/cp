N, W = list(map(int, input().split()))
I = []
for i in range(N):
    I.append(tuple(map(int, input().split())))

memo = {}
def knapsack2(N, W, I, val=0):
    I2 = tuple(sorted(I))
    if I2 in memo:
        return memo[I2]
    if W == 0 or N == 0 or not I:
        memo[I2] = val
        return val
    
    maxval = 0
    for i in range(len(I)):
        if W-I[i][0] < 0:
            res = val
            memo[tuple(sorted(I[:i]+I[i+1:]))] = val
        else:
            res = knapsack2(N-1, W-I[i][0], I[:i]+I[i+1:], val + I[i][1])
        if res > maxval:
            maxval = res
    memo[I2] = maxval
    return maxval

print(knapsack2(N, W, I))
    