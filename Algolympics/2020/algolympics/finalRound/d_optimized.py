t = int(input())
for x in range(t):
    r, c = list(map(int, input().split()))
    wiring = []
    for y in range(r):
        wiring.append(input())
    
    pairs = []
    unpaired = ''
    
    # getting all legs
    for row in range(len(wiring)):
        for col in range(len(wiring[row])):
            if wiring[row][col].isalnum():
                unpaired += wiring[row][col]
                
    
    # by row first
    for row in wiring:
        line = row
        
        first = ''
        second = ''
        
        first_found = False
        second_found = False
        wired = False
        for z in line:
            if not wired: # get first pair
                if z.isalnum():
                    first = z
                    first_found = True
                elif first_found:
                    if z in ['-', '+']:
                        wired = True
                    else:
                        #if first not in unpaired:
                        #    unpaired.append(first)
                        first_found = False
            else: # get second pair
                if z.isalnum():
                    second = z
                    second_found = True
                else:
                    if z not in ['-', '+']:
                        wired = False
                        #if first not in unpaired:
                        #    unpaired.append(first)
                        first_found = False
            
            # check if pair is found and if it's already in list of pairs
            if first_found and second_found:
                pair = ''.join(sorted([first, second]))
                if pair not in pairs:
                    pairs.append(pair)
                wired = False
                first_found = False
                second_found = False
                    
    # by column now
    for col in range(len(wiring[0])):
        line = [a[col] for a in wiring]
        
        first = ''
        second = ''
        
        first_found = False
        second_found = False
        wired = False
        for z in line:
            if not wired: # get first pair
                if z.isalnum():
                    first = z
                    first_found = True
                elif first_found:
                    if z in ['|', '+']:
                        wired = True
                    else:
                        #if first not in unpaired:
                        #    unpaired.append(first)
                        first_found = False
            else: # get second pair
                if z.isalnum():
                    second = z
                    second_found = True
                else:
                    if z not in ['|', '+']:
                        wired = False
                        #if first not in unpaired:
                        #   unpaired.append(first)
                        first_found = False
            
            # check if pair is found and if it's already in list of pairs
            if first_found and second_found:
                pair = ''.join(sorted([first, second]))
                if pair not in pairs:
                    pairs.append(pair)
                wired = False
                first_found = False
                second_found = False
    
    pairs = sorted(pairs)    
    for x in ''.join(pairs):
        unpaired = unpaired.replace(x, '')
    unpaired = ''.join(sorted(list(unpaired)))
    
    print(len(unpaired))
    #if len(unpaired) > 0:
    print(' '.join(list(unpaired)))
    print(len(pairs))
    #if len(pairs) > 0:
    print(' '.join(list(pairs)))
    
    
    
        