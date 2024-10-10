from collections import deque

N, W = list(map(int, input().split()))
I = []
for i in range(N):
    I.append(list(map(int, input().split())))

maxval = 0
q = deque([[0, 0, I]]) # weight, value, available items

while q:
    curr = q.popleft()
    w = curr[0]
    v = curr[1]
    I2 = curr[2]
    for i in range(len(I2)):
        wv = I2[i]
        neww = w+wv[0]
        newv = v+wv[1]
        newi = I2[:i]+I2[i+1:]
        if neww <= W:
            if newv > maxval:
                maxval = newv
            if newi:
                q.append([neww, newv, newi])
print(maxval)