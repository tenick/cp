class Solution(object):
    def merge(self, intervals):
        intervals = sorted(intervals, key=lambda x: x[0])
        low = intervals[0][0]
        high = intervals[0][1]
        
        nonOverlappingIntervals = []
        currInterval = []
        for interval in intervals:
            if interval[1] <= high:
                continue
            elif interval[0] <= high and interval[1] > high:
                high = interval[1]
            else:
                nonOverlappingIntervals.append([low, high])
                low, high = interval
        nonOverlappingIntervals.append([low, high])
        return nonOverlappingIntervals