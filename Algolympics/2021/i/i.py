t = int(input())
while(t):
    n = int(input())
    unsure_count = 0
    can_be_zero = False
    votes = []
    output = []
    
    # init votes list
    for i in range(n + 1):
        votes.append(0)
        
    # getting votes
    input_votes = list(map(int, input().split()))
    for vote in input_votes:
        if vote == -1:
            unsure_count += 1
        else:
            votes[vote] += 1
    
    max_vote = max(votes)
    
    # check if -1 max
    if unsure_count > max_vote:
        for i in range(n + 1):
            output.append(str(i))
        print(' '.join(output))
    # check if -1 == 0
    elif unsure_count == 0:
        count_maxes = 0
        crew_index = 0
        more_than_1 = False
        for i in range(n + 1):
            if votes[i] == max_vote:
                count_maxes += 1
                crew_index = i
            if count_maxes > 1:
                more_than_1 = True
                print('0')
                break
        if not more_than_1:
            print(crew_index)
    # -1 votes != 0 and -1 votes <= crew_vote
    else:
        for i in range(n + 1):
            if (votes[i] + unsure_count > max_vote):
                if i == 0:
                    can_be_zero = True
                else:
                    output.append(str(i))
            elif votes[i] + unsure_count == max_vote:
                can_be_zero = True
        if can_be_zero:
            output = ['0'] + output
        print(' '.join(output))
    
    t -= 1
