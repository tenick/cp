class Solution(object):
    def numIslands(self, grid):
        visited = set()
        stack = []
        islands = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    if (i, j) not in visited:
                        stack = [(i, j)]
                        while stack:
                            origin = stack.pop()
                            visited.add(origin)
                            stack += self.getNeighbors(origin, grid, visited)
                        islands += 1
        
        return islands
    
    def getNeighbors(self, origin, grid, visited):
        d = {'u': (0, 1), 'r': (1, 0), 'd': (0, -1), 'l': (-1, 0)}
        neighbors = []
        
        for a in d:
            neighbor = (origin[0] + d[a][0], origin[1] + d[a][1])
            if neighbor[0] >= 0 and neighbor[1] >= 0 and neighbor[0] < len(grid) and neighbor[1] < len(grid[0]) and grid[neighbor[0]][neighbor[1]] == '1' and neighbor not in visited:
                neighbors.append(neighbor)
                visited.add(neighbor)
        return neighbors
        