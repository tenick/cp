class Solution(object):
    def groupAnagrams(self, strs):
        dic = {}
        for word in strs:
            if ''.join(sorted(word)) in dic:
                dic[''.join(sorted(word))].append(word)
            else:
                dic[''.join(sorted(word))] = [word]
        return [dic[k] for k in dic]