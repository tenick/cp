import math

t = int(input())
for _ in range(t):
    n = int(input())
    N = list(map(int, input().split()))
    m = int(input())
    M = list(map(int, input().split()))
    
    gcd = math.gcd(n, m)
    lcm = n // gcd * m

    knownMax = [max([N[j * gcd + i] for j in range(n // gcd)]) for i in range(gcd)]
    maxVal = 0
    for i in range(m):
        maxVal = max(maxVal, knownMax[i % gcd] + M[i])
    
    print(maxVal)
