class Solution(object):
    def maxArea(self, height):
        p1 = 0
        p2 = len(height) - 1
        maxWaterAmt = 0
        while p1 < p2:
            waterAmt = (p2 - p1) * min(height[p1], height[p2])
            maxWaterAmt = waterAmt if waterAmt > maxWaterAmt else maxWaterAmt
            p1 += 1
            p2 -= 1
            if height[p1-1] < height[p2+1]:
                p2 += 1
            elif height[p1-1] > height[p2+1]:
                p1 -= 1
        return maxWaterAmt