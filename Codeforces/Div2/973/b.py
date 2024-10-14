t = int(input())
while t != 0:
    n = int(input())
    p = list(map(int, input().split()))
    sm = 0
    for i in range(n-2):
        sm += p[i]
    sm = p[n-2] - sm
    print(p[n-1] - sm)
    t -= 1