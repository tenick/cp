class Node:
    def __init__(self, i, val):
        self.i = i
        self.val = val
        self.neighbors : set[Node] = set()
        self.isLast = False
    
    def __str__(self) -> str:
        return str({self.i: self.val}) + '->' + str({i.i: i.val for i in self.neighbors})

def getMaxMagnitude(nodes: list[Node]):
    if len(nodes) == 1:
        return nodes[0].val

    maxMagnitude = 0
    stack = [[nodes[0].val, node] for node in nodes[0].neighbors]
    while stack:
        currMinShield, node = stack.pop()
        currMinShield = min(currMinShield, node.val)
        if len(node.neighbors) == 0 and node.isLast:
            maxMagnitude = max(maxMagnitude, currMinShield)
        else:
            stack += [[currMinShield, node] for node in node.neighbors]

    return maxMagnitude

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    s = [Node(int(i), int(j)) for i, j in enumerate(input().split())]
    s[-1].isLast = True

    for i in range(m):
        tp1, tp2 = map(int, input().split())
        if tp1 == tp2:
            continue
        if tp1 > tp2:
            temp = tp2
            tp2 = tp1
            tp1 = temp
        s[tp1 - 1].neighbors.add(s[tp2 - 1])
    
    print(getMaxMagnitude(s))
