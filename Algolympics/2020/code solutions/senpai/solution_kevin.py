for cas in range(int(input())):
    q, g = map(int, input().split())
    w2 = sum(int(w)**2 for w in input().split())
    f, c = map(sum, zip(*(map(int, input().split()) for qq in range(q))))
    print(f"{0 if c <= 0 else c / (g * w2**.5 - f) if f < 0 else c * (g * w2**.5 + f) / (g**2 * w2 - f**2):.20f}")
