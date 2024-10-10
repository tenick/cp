mod = 104857601
l, w = [int(x) for x in input().split()]
s, d = l + w, l - w
inv = [1]*(w+1)
ans_pos = ans_neg = 0
cs0 = cs2 = 1
for j in range(1,w+1):
    if j >= 2: inv[j] = -(mod // j) * inv[mod % j] % mod
    if (j-w+0) % (d+2) == 0: ans_pos = (ans_pos + cs0) % mod
    if (j-w+1) % (d+2) == 0: ans_neg = (ans_neg + cs2) % mod
    cs0 = cs0 * (s+1-j) * inv[j] % mod
    cs2 = cs2 * (s-1-j) * inv[j] % mod
print((ans_pos - 4*ans_neg) % mod)
