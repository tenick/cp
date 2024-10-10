def bad(m, c0, c1):
    return c0 and c1 if m == c0 + c1 else m % 2 == 0 and c0 % 2

def write_move(n, *move):
    x = ['0']*n
    for i in move: x[i] = '1'
    return ''.join(x)

def _solve(m, c0, c1):
    n = len(c0) + len(c1)
    while c0:
        if m == n or len(c0) <= m and m % 2 and len(c0) % 2:
            ex = m - len(c0)
            yield write_move(n, *c0, *c1[:ex])
            c0, c1 = c1[:ex], c1[ex:] + c0
        else:
            ex = (*c0[2:], *c1)[:m - 1]
            for w in c0[:2]: yield write_move(n, w, *ex)
            c0, c1 = c0[2:], c1 + c0[:2]

def solve(m, s):
    c = [], []
    for i, v in enumerate(map(int, s)): c[v].append(i)
    return None if bad(m, *map(len, c)) else (*_solve(m, *c),)

def main():
    for cas in range(int(input())):
        n, m = map(int, input().split())
        moves = solve(m, input())
        if moves is None:
            print("CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS")
        else:
            print(len(moves), *moves, sep='\n')

if __name__ == '__main__': main()
