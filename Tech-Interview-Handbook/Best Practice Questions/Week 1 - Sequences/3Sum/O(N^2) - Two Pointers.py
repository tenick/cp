class Solution(object):
    def threeSum(self, nums):
        solution = []
        nums.sort()
        seen = None
        
        for i in range(len(nums) - 2):
            if nums[i] == seen:
                continue
            
            a = nums[i]
            seen = a
            
            # two-pointer
            p1 = i+1
            p2 = len(nums) - 1
            p1Seen = None
            p2Seen = None
            while p1 < p2 and p2 > p1:
                if p1Seen == nums[p1]:
                    p1 += 1
                    continue
                if p2Seen == nums[p2]:
                    p2 -= 1
                    continue
                
                twoPtrSum = nums[p1] + nums[p2]
                
                if twoPtrSum + a == 0:
                    solution.append([a, nums[p1], nums[p2]])
                    p1Seen = nums[p1]
                    p1 += 1
                elif twoPtrSum + a > 0:
                    p2Seen = nums[p2]
                    p2 -= 1
                else:
                    p1Seen = nums[p1]
                    p1 += 1
                    
        return solution
            