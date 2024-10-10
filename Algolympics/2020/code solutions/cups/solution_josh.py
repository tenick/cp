invalid_string = 'CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS'

t = int(input())
for cn in range(t):
    n,m = map(int,input().split())
    states = list(map(int,list(input())))
    
    O = states.count(0)

    def even_case():
        global O
        prev = 0
        while O>0:
            a = states.index(0)
            b = states.index(0,a+1)
            prev = b+1

            out = ['0']*n
            p = 0
            count = m-1
            while count>0:
                while p==a or p==b:
                    p += 1
                out[p] = '1'
                count -= 1
                p += 1
            
            out[a] = '1'
            print(''.join(out))
            out[a] = '0'
            out[b] = '1'
            print(''.join(out))

            states[a] = 1
            states[b] = 1
            O -= 2

    # Special case
    if m==n:
        if O==0:
            print("0")
        elif O==n:
            print("1")
            print(''.join(['1']*n))
        else:
            print(invalid_string)
    elif O%2==0:
        print(O)
        even_case()
    elif O%2==1:
        if m%2==0:
            print(invalid_string)
        else:
            p = states.index(0)
            if p<m:
                out = ['1']*m + ['0']*(n-m)
            else:
                out = ['1']*(m-1) + ['0']*(n-m+1)
                out[p] = '1'
            for i in range(n):
                if out[i]=='1':
                    states[i] = states[i]^1
            
            O = states.count(0)
            print(O+1)
            print(''.join(out))
            even_case()
