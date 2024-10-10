t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    enlSet = {1}

    for __ in range(k):
        p1, p2 = map(int, input().split())
        if p1 in enlSet or p2 in enlSet:
            enlSet.add(p1)
            enlSet.add(p2)
    print(' '.join(map(str, sorted(enlSet))))
    