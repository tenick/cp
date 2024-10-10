m = int(input())
for x in range(m):
    hacked = False
    a = int(input())
    A = []
    for y in range(a):
        A.append(input())
    p = int(input())
    P = []
    for z in range(p):
        P.append(input())
    
    A.sort()
    P.sort()
    for y in range(len(P)):
        if P[y] not in A:
            print("STAR STREAM HACKED!!!")
            hacked = True
            break
    if not hacked:
        if len(P) > len(A) // 2:
            print("START THE MEETING.")
        else:
            print("NO STARS IN THE NIGHT SKY.")