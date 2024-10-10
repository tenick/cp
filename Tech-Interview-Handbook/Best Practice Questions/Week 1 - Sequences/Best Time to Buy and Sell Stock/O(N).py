class Solution(object):
    def maxProfit(self, prices):
        currPrice = prices[0]
        maxProfit = 0
        for i in range(1, len(prices)):
            if prices[i] < currPrice:
                currPrice = prices[i]
            else:
                profit = prices[i] - currPrice
                maxProfit = profit if profit > maxProfit else maxProfit
        return maxProfit
        