class Solution(object):
    def pacificAtlantic(self, heights):
        stack = []
        result = []
        saveInfo = [[None for x in range(len(heights[0]))] for y in range(len(heights))]
        
        for i in range (len(heights)):
            for j in range (len(heights[i])):
                stack = [(i, j)]
                head = [i,j]
                visited = set()
                flowsToPO = False
                flowsToAO = False
                found = False
                
                if saveInfo[stack[0][0]][stack[0][1]] is not None:
                    if not saveInfo[stack[0][0]][stack[0][1]]:
                        continue
                
                while stack and not (flowsToPO and flowsToAO):
                    origin = stack.pop()
                    
                    # check first if this is in saveInfo
                    if saveInfo[origin[0]][origin[1]] is not None:
                        if saveInfo[origin[0]][origin[1]]:
                            result.append(head)
                            found = True
                            break
                    
                    # check if flows to Pacific Ocean
                    if origin[0] == 0 or origin[1] == 0:
                        flowsToPO = True
                    # check if flows to Atlantic Ocean
                    if origin[0] == len(heights) - 1 or origin[1] == len(heights[i]) - 1:
                        flowsToAO = True
                        
                    visited.add(origin)
                    stack += self.getNeighbors(origin, heights, visited)
                
                if found:
                    continue
                
                if flowsToPO and flowsToAO:
                    saveInfo[i][j] = True
                    result.append([i, j])
                else:
                    for k in visited:
                        saveInfo[k[0]][k[1]] = False
                
        return result
                
    def getNeighbors(self, origin, grid, visited):
        d = {'u': (0, 1), 'r': (1, 0), 'd': (0, -1), 'l': (-1, 0)}
        neighbors = []
        
        for a in d:
            neighbor = (origin[0] + d[a][0], origin[1] + d[a][1])
            if neighbor[0] >= 0 and neighbor[1] >= 0 and neighbor[0] < len(grid) and neighbor[1] < len(grid[0]) and neighbor not in visited and grid[neighbor[0]][neighbor[1]] <= grid[origin[0]][origin[1]]:
                neighbors.append(neighbor)
        return neighbors