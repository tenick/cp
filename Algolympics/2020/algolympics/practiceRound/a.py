s = int(input())
S = []
for x in range(s):
	S.append(input().lower())

for x in S:
    if 'president' in x:
        print("IMPORTANT")
    else:
        print("NOT IMPORTANT")