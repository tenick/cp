a = int(input())
b = [input().split() for _ in range(a * 2)]
ans = []
dic = {}

for i in b:
    if i[0] in dic:
        if not dic[i[0]][1]:
            dic[i[0]][1] = True
            secs = int(i[1]) - dic[i[0]][0]
            out = " has reasonable work hours!"
            if secs > 216000:
                out = " overworked their PR0xF!"
            ans.append([i[0], out])
    else:
        dic[i[0]] = [int(i[1]), False]

ans.sort(key=lambda x: x[0])
for x in ans:
    print(''.join(x))
