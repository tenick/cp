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
    else:
        innovative_word = False
        
        # checking word by word
        for i in range(len(rp_words)):
            # word has same length
            if len(rp_words[i]) == len(rpi_words[i]):
                # test for 1 length word
                if len(rp_words[i]) == 1:
                    if rp_words[i] != rpi_words[i]:
                        innovative_word = True
                        break
                    
                unmatched = 0
                s1 = ""
                s2 = ""
                # checking letter by letter
                for j in range(len(rp_words[i])):
                    if rp_words[i][j] != rpi_words[i][j]:
                        s1 += rp_words[i][j]
                        s2 += rpi_words[i][j]
                        unmatched += 1
                    if unmatched > 2:
                        innovative_word = True
                        break
                if innovative_word:
                    break
                length = len(set(s1 + s2))
                if length == 0 or length == 2:
                    continue
                else:
                    innovative_word = True
                    break
                    
            # word is innovative
            else:
                innovative_word = True
                break
        if not innovative_word:
            print(x + 1)
            innovative_work = False
        
if innovative_work:
    print("INNOVATIVE WORK")