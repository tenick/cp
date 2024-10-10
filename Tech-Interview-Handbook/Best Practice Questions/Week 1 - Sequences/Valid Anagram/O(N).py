class Solution(object):
    def isAnagram(self, s, t):
        letters = {}
        for c in s:
            if c not in letters:
                letters[c] = [0, 0]
            letters[c][0] += 1
        for c in t:
            if c not in letters:
                return False
            letters[c][1] += 1
        for letter in letters:
            if letters[letter][0] != letters[letter][1]:
                return False
        return True