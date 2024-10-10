class Solution(object):
    def findMin(self, nums):
        if nums[0] < nums[len(nums)-1]: # guaranteed no rotation
            return nums[0]
        
        l = 0
        r = len(nums) - 1
        mid = (l + r) // 2
        while mid != l and mid != r:
            l, r = (mid, r) if nums[mid] > nums[l] else (l, mid)
            mid = (l + r) // 2
        
        return nums[r]