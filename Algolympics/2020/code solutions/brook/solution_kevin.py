input()
print(*(w for h, w in sorted(zip(*[[*map(int, input().split())] for it in range(2)][::-1]))))
