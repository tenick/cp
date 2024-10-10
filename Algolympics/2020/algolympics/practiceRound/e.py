t = int(input())
for x in range(t):
    plywoods = []
    n = int(input())
    for y in range(n):
        plywoods.append(list(map(int, input().split())))
    
    print("Before Sort", plywoods)
    plywoods.sort(key=lambda x: x[1])
    print("After Sort", plywoods)
    
# 1
# 3
# 300 300
# 120 100
# 10 140

