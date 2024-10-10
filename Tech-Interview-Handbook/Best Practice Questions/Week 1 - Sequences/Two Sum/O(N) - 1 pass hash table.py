class Solution(object):
    def twoSum(self, nums, target):
        pair_candidates = {}
        index = 0
        for n in nums:
            pair = target - n
            if pair in pair_candidates:
                return [index, pair_candidates[pair]]
            pair_candidates[n] = index
            index += 1