n = int(input())
rp = input()
innovative_work = True

for x in range(n):
    rpi = input()
    
    rp_words = rp.split()
    rpi_words = rpi.split()
    
    # move on if totto's research paper title no. of words != ith research paper title no. of words
    if len(rp_words) != len(rpi_words):
        continue
    else: # prove that totto's research paper wasn't plagiarized
        innovative = False
        for i in range(len(rp_words)): # get words of each research paper and compare word to word until end to know if plagiarized
            if len(rp_words[i]) == len(rpi_words[i]): # if words are same in length
                # 1. if len == 1, check if 2 words are equal, if not break, if equal continue
                if len(rp_words[i]) == 1:
                    if rp_words[i] == rpi_words[i]:
                        continue
                    innovative = True
                    break
                
                # 2. check if word only has 1 letter pair swapped OR equal word. If there is, can be plagiarized so continue, if no break
                innovative2 = False
                unmatched = 0
                s1 = ""
                s2 = ""
                for j in range(len(rp_words[i])):
                    if rp_words[i][j] != rpi_words[i][j]:
                        unmatched += 1
                        s1 += rp_words[i][j]
                        s2 += rpi_words[i][j]
                    if unmatched > 2:
                        innovative2 = True
                        break
                if innovative2: # break if innovative
                    innovative = True
                    break
                else:
                    if sorted(s1) == sorted(s2):
                        continue
                    #if unmatched == 0 or (unmatched == 2 and len(set(s1 + s2)) == 2):
                    #    continue
                    innovative = True
                    break
            else: # words aren't equal, therefore not plagiarized, innovative
                innovative = True
                break
            
        if not innovative:
            innovative_work = False
            print(x + 1)
if innovative_work:
    print("INNOVATIVE WORK")