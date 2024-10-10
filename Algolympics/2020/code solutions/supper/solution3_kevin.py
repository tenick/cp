mod = 104857601
def compute_inverses(n):
    """ compute inverses up to n """
    inv = [1]*(n+1)

    # compute n!
    for i in range(1,n+1): inv[n] = inv[n] * i % mod

    # compute (n!)^-1
    inv[n] = pow(inv[n], mod - 2, mod)

    # compute inverse factorials (i!)^-1 as (i-1)!^-1 = i*i!^-1
    for i in range(n,0,-1): inv[i - 1] = inv[i] * i % mod

    # compute i^-1 as (i!)^-1 * (i-1)!
    f = 1
    for i in range(1,n+1):
        inv[i] = inv[i] * f % mod
        f = f * i % mod

    return inv

l, w = [int(x) for x in input().split()]
s, d = l + w, l - w
inv = compute_inverses(w)
ans_pos = ans_neg = 0
cs0 = cs2 = 1
for j in range(1,w+1):
    if (j-w+0) % (d+2) == 0: ans_pos = (ans_pos + cs0) % mod
    if (j-w+1) % (d+2) == 0: ans_neg = (ans_neg + cs2) % mod
    cs0 = cs0 * (s+1-j) * inv[j] % mod
    cs2 = cs2 * (s-1-j) * inv[j] % mod
print((ans_pos - 4*ans_neg) % mod)
