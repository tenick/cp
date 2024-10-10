mod = 999983
for cas in range(int(input())):
    n, k, l = map(int, input().split())
    poly = [1]
    for v in {*map(int, input().split())}:
        poly = [*map(sum, zip([*poly, 0], [0, *(a * -v % mod for a in poly)]))]
    res = n if len(poly) - 1 <= k else 0
    print(res)
    for m in range(1, res+1): print(len(poly) - 1, *(a * m % mod for a in poly))
