a = int(input())
for _ in range(a):
    r, c = map(int, input().split())
    grid = [input() for __ in range(r)]
    
    out = "DIPLOMACY!"
    for planet in grid:
        x = 0
        for ch in planet:
            if ch == 'X':
                x += 1
        if x == c:
            out = 'FIREWORKS!'
            break
    print(out)
    
    