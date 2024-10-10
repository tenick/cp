t = 5
for x in range(t):
    result = "VIRSTOP"
    date = list(map(str, input().split()))
    if date[1] == 'September':
        if int(date[0]) >= 16 and int(date[0]) <= 30:
            result = "VIRGO"
    elif date[1] == 'October':
        if int(date[0]) >= 1 and int(date[0]) <= 30:
            result = "VIRGO"
    print(result)