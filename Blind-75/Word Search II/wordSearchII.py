board = [["a","a"],["a","a"]]
words = ["aaaa"]
board = [["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"],
         ["a","a","a","a","a","a","a","a","a","a","a","a"]]
words = ["lllllll","fffffff","ssss","s","rr","xxxx","ttt","eee","ppppppp","iiiiiiiii","xxxxxxxxxx","pppppp","xxxxxx","yy","jj","ccc","zzz","ffffffff","r","mmmmmmmmm","tttttttt","mm","ttttt","qqqqqqqqqq","z","aaaaaaaa","nnnnnnnnn","v","g","ddddddd","eeeeeeeee","aaaaaaa","ee","n","kkkkkkkkk","ff","qq","vvvvv","kkkk","e","nnn","ooo","kkkkk","o","ooooooo","jjj","lll","ssssssss","mmmm","qqqqq","gggggg","rrrrrrrrrr","iiii","bbbbbbbbb","aaaaaa","hhhh","qqq","zzzzzzzzz","xxxxxxxxx","ww","iiiiiii","pp","vvvvvvvvvv","eeeee","nnnnnnn","nnnnnn","nn","nnnnnnnn","wwwwwwww","vvvvvvvv","fffffffff","aaa","p","ddd","ppppppppp","fffff","aaaaaaaaa","oooooooo","jjjj","xxx","zz","hhhhh","uuuuu","f","ddddddddd","zzzzzz","cccccc","kkkkkk","bbbbbbbb","hhhhhhhhhh","uuuuuuu","cccccccccc","jjjjj","gg","ppp","ccccccccc","rrrrrr","c","cccccccc","yyyyy","uuuu","jjjjjjjj","bb","hhh","l","u","yyyyyy","vvv","mmm","ffffff","eeeeeee","qqqqqqq","zzzzzzzzzz","ggg","zzzzzzz","dddddddddd","jjjjjjj","bbbbb","ttttttt","dddddddd","wwwwwww","vvvvvv","iii","ttttttttt","ggggggg","xx","oooooo","cc","rrrr","qqqq","sssssss","oooo","lllllllll","ii","tttttttttt","uuuuuu","kkkkkkkk","wwwwwwwwww","pppppppppp","uuuuuuuu","yyyyyyy","cccc","ggggg","ddddd","llllllllll","tttt","pppppppp","rrrrrrr","nnnn","x","yyy","iiiiiiiiii","iiiiii","llll","nnnnnnnnnn","aaaaaaaaaa","eeeeeeeeee","m","uuu","rrrrrrrr","h","b","vvvvvvv","ll","vv","mmmmmmm","zzzzz","uu","ccccccc","xxxxxxx","ss","eeeeeeee","llllllll","eeee","y","ppppp","qqqqqq","mmmmmm","gggg","yyyyyyyyy","jjjjjj","rrrrr","a","bbbb","ssssss","sss","ooooo","ffffffffff","kkk","xxxxxxxx","wwwwwwwww","w","iiiiiiii","ffff","dddddd","bbbbbb","uuuuuuuuu","kkkkkkk","gggggggggg","qqqqqqqq","vvvvvvvvv","bbbbbbbbbb","nnnnn","tt","wwww","iiiii","hhhhhhh","zzzzzzzz","ssssssssss","j","fff","bbbbbbb","aaaa","mmmmmmmmmm","jjjjjjjjjj","sssss","yyyyyyyy","hh","q","rrrrrrrrr","mmmmmmmm","wwwww","www","rrr","lllll","uuuuuuuuuu","oo","jjjjjjjjj","dddd","pppp","hhhhhhhhh","kk","gggggggg","xxxxx","vvvv","d","qqqqqqqqq","dd","ggggggggg","t","yyyy","bbb","yyyyyyyyyy","tttttt","ccccc","aa","eeeeee","llllll","kkkkkkkkkk","sssssssss","i","hhhhhh","oooooooooo","wwwwww","ooooooooo","zzzz","k","hhhhhhhh","aaaaa","mmmmm"]


# build the search dictionary
searchDict = {}
wordPathDict = {}
for word in words:
    currDict = searchDict
    currList = []
    for c in word:
        if c not in currDict:
            currDict[c] = [{}, False]
        currList = currDict[c]
        currDict = currDict[c][0]
    currList[1] = True
    if word[0] not in wordPathDict:
        wordPathDict[word[0]] = set()
    wordPathDict[word[0]].add(word)

# store search indices O(12x12)
searchCells = {}
a = 0
for i in board:
    b = 0
    for j in i:
        if j in searchDict:
            if j in searchCells:
                searchCells[j].append((a, b))
            else:
                searchCells[j] = [(a, b)]
        b += 1
    a += 1

def getNeighbors(index, origins=set()):
    neighbors = []
    dic = {"U": (-1, 0), "D": (1, 0), "L": (0, -1), "R": (0, 1)}
    for d in dic:
        nbIndex = (index[0] + dic[d][0], index[1] + dic[d][1])
        if not (nbIndex[0] < 0 or nbIndex[0] == len(board)) and not (nbIndex[1] < 0 or nbIndex[1] == len(board[0])):
            if origins != None:
                if nbIndex not in origins:
                    neighbors.append(nbIndex)
            else:
                neighbors.append(nbIndex)
    return neighbors

# do the search (searchInfo = (index, parentIndex, currentWord, dictionaryDepth, isWord))
foundWords = {}
allWordsSet = set()
searchStack = []
for i in searchCells:
    for searchCell in searchCells[i]:
        if i in foundWords and len(foundWords[i]) == len(wordPathDict[i]):
            break
        
        searchStack = [((searchCell), set(), i, searchDict[i][0], searchDict[i][1])]
        
        while searchStack:
            searchInfo = searchStack.pop()
            
            newOrigins = set(searchInfo[1])
            newOrigins.add(searchInfo[0])
            
            if searchInfo[4]:
                allWordsSet.add(searchInfo[2])
                if i not in foundWords:
                    foundWords[i] = set()
                foundWords[i].add(searchInfo[2])
                    
            neighbors = getNeighbors(searchInfo[0], searchInfo[1])
            for neighbor in neighbors:
                c = board[neighbor[0]][neighbor[1]]
                if c in searchInfo[3]:
                    searchStack.append((neighbor, newOrigins, searchInfo[2]+c, searchInfo[3][c][0], searchInfo[3][c][1]))

print(list(allWordsSet))





















