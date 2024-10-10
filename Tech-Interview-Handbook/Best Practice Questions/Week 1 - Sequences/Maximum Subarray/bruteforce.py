class Solution(object):
    def maxSubArray(self, nums):
        maxSubSum = -10000
        
        for i in range(len(nums)):
            for j in range(i+1):
                
                subSum = 0
                for k in range(len(nums) - i):
                    subSum += nums[j+k]
                    
                maxSubSum = subSum if subSum > maxSubSum else maxSubSum
                
        return maxSubSum