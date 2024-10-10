class Solution(object):
    def threeSum(self, nums):
        positive = {}
        negative = {}
        zeroes = 0
        solution = []
        solutionSet = set()
        
        # build dicts
        for n in nums:
            if n < 0:
                negative[n] = True if n in negative else False
            elif n > 0:
                positive[n] = True if n in positive else False 
            else:
                zeroes += 1
        
        if zeroes >= 3:
            solution.append([0, 0, 0])
        if len(positive) == 0 or len(negative) == 0:
            return solution
        
        for n in negative:
            for p in positive:
                used = {n, p}
                complement = -(n + p)
                
                if complement > 0:
                    if complement in positive:
                        if complement in used:
                            if positive[complement]:
                                if tuple(sorted([n, p, complement])) not in solutionSet:
                                    solution.append([n, p, complement])
                                    solutionSet.add(tuple(sorted([n, p, complement])))
                        else:
                            if tuple(sorted([n, p, complement])) not in solutionSet:
                                solution.append([n, p, complement])
                                solutionSet.add(tuple(sorted([n, p, complement])))
                elif complement < 0:
                    if complement in negative:
                        if complement in used:
                            if negative[complement]:
                                if tuple(sorted([n, p, complement])) not in solutionSet:
                                    solution.append([n, p, complement])
                                    solutionSet.add(tuple(sorted([n, p, complement])))
                        else:
                            if tuple(sorted([n, p, complement])) not in solutionSet:
                                solution.append([n, p, complement])
                                solutionSet.add(tuple(sorted([n, p, complement])))
                else:
                    if zeroes > 0:
                        if tuple(sorted([n, p, 0])) not in solutionSet:
                            solution.append([n, p, 0])
                            solutionSet.add(tuple(sorted([n, p, 0])))
        return solution