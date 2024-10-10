class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0])
        
        erasure_count = 0
        interval_to_compare = intervals[0]
        for i in range(1, len(intervals)):
            interval = intervals[i]
            if interval_to_compare[1] > interval[0]:
                erasure_count += 1
                if interval_to_compare[1] > interval[1]:
                    interval_to_compare = interval
            else:
                interval_to_compare = interval
        return erasure_count
            