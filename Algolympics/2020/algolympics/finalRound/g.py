g = int(input())
for x in range(g):
    r, c = list(map(int, input().split()))
    grid = []
    grid_values = []
    total = 0
    shot_areas = []
    
    # get grid
    for i in range(r):
        grid.append(list(map(int, list(input()))))
        
    # get grid values
    for i in range(r):
        grid_values.append(list(map(int, input().split())))
    
    a = int(input())
    
    # SOLUTION
    
    row_sum = []
    col_sum = []
    
    # get row sum
    for i in range(len(grid)):
        rsum = 0
        curr_sum = 0
        for j in range(len(grid[i])):
            rsum += grid_values[i][j]
            curr_sum += (grid[i][j] * grid_values[i][j])
        row_sum.append(['R', i, rsum, curr_sum, rsum - curr_sum])
    
    # get col sum
    for i in range(c):
        csum = 0
        curr_sum = 0
        for j in range(r):
            csum += grid_values[j][i]
            curr_sum += (grid[j][i] * grid_values[j][i])
        col_sum.append(['C', i, csum, curr_sum, csum - curr_sum])
    
    # descending sort
    row_sum.sort(key=lambda x: x[4])
    col_sum.sort(key=lambda x: x[4])
    
    # get current star count
    total = sum([x[3] for x in row_sum])
    print(total)
    #-----------------
    
    # shooting time
    for i in range(a):
        rr = row_sum[-1]
        cc = col_sum[-1]
        
        # shoot at row
        if rr[4] > cc[4]:
            if rr[4] > rr[3]: # shoot
                total -= rr[3]
                total += rr[4]
                # update columns and grid
                col_sum.sort(key=lambda x: x[1])
                for j in len(grid[rr[1]]):
                    val = grid[rr[1]][j]
                    if val == 1:
                        col_sum[j][3] -= grid_values[rr[1]][j]
                        grid[rr[1]][j] = 0
                    else:
                        col_sum[j][3] += grid_values[rr[1]][j]
                        grid[rr[1]][j] = 1
                        
                shot_areas.append(rr)
                row_sum.remove(rr)        
                 
                col_sum.sort(key=lambda x: x[4])
        
        # shoot at col
        if cc[4] > rr[4]:
            if cc[4] > cc[3]: # shoot
                total -= cc[3]
                total += cc[4]
                # update columns and grid
                row_sum.sort(key=lambda x: x[1])
                for j in range(r):
                    val = grid[j][cc[1]]
                    if val == 1:
                        row_sum[j][3] -= grid_values[j][cc[1]]
                        grid[j][cc[1]] = 0
                    else:
                        row_sum[j][3] += grid_values[j][cc[1]]
                        grid[j][cc[1]] = 1
                        
                shot_areas.append(cc)
                col_sum.remove(cc)
                
                row_sum.sort(key=lambda x: x[4])
                            
            
          
    
    
    
    print(total)
    
    
    
    
    
    
    
    
    
    