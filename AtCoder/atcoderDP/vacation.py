N = int(input())
A = []
for i in range(N):
    A.append(list(map(int, input().split())))
for i in range(N - 1):
    a1 = A[i][:]
    a2 = A[i+1][:]
    newa2 = A[i+1][:]
    for j in range(len(a1)):
        for k in range(len(a2)):
            if j != k:
                val = a1[j] + a2[k]
                newa2[k] = val if val > newa2[k] else newa2[k]
    A[i+1] = newa2
print(max(A[N-1]))
              
    
