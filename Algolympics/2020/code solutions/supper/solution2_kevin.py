mod = 104857601
l, w = [int(x) for x in input().split()]
s, d = l + w, l - w

fac = [1]*(s+1)
for i in range(1,s+1):
    fac[i] = i * fac[i - 1] % mod

ifc = [1]*(s+1)
ifc[s] = pow(fac[s], mod - 2, mod)
for i in range(s,0,-1):
    ifc[i - 1] = i * ifc[i] % mod

ans_pos = 0
for i in range((w - 1) // (d + 2) + 1):
    ans_pos = (ans_pos + ifc[w - (d + 2)*i - 1] * ifc[l + (d + 2)*i + 1]) % mod

ans_neg = 0
for i in range((w - 2) // (d + 2) + 1):
    ans_neg = (ans_neg + ifc[w - (d + 2)*i - 2] * ifc[l + (d + 2)*i + 0]) % mod

print((fac[s]*ans_pos - 4*fac[s-2]*ans_neg) % mod)
