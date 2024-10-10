n = int(input())
rp = input()
innovative_work = True
for x in range(n):
    rpi = input()
    
    rp_words = rp.split()
    rpi_words = rpi.split()
    if len(rp_words) != len(rpi_words):
        continue
    else:
        innovative_word = True
        for i in range(len(rp_words)):
            if sorted(rp_words[i]) != sorted(rpi_words[i]):
                innovative_word = False
                break
        if not innovative_word:
            continue
        innovative_work = False
        print(x+1)
if innovative_work:
    print("INNOVATIVE WORK")

