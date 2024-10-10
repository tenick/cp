class Solution(object):
    def productExceptSelf(self, nums):
        prefix = []
        suffix = []
        
        for i in nums:
            if not prefix:
                prefix.append(i)
            else:
                prefix.append(i * prefix[-1])
        for i in reversed(nums):
            if not suffix:
                suffix.append(i)
            else:
                suffix.append(i * suffix[-1])
        
        answer = []
        for i in range(len(nums)):
            prefix_index = i - 1
            suffix_index = -(i + 1) - 1
            
            prefix_value = 1
            suffix_value = 1
            if prefix_index != -1:
                prefix_value = prefix[prefix_index]
            if abs(suffix_index) <= len(suffix):
                suffix_value = suffix[suffix_index]
            
            answer.append(prefix_value * suffix_value)
        
        return answer

# using division
class Solution2(object):
    def productExceptSelf(self, nums):
        prod = 1
        for i in nums:
            prod *= i
            if prod == 0:
                prod2 = 1
                answer = [0 for j in nums]
                zero_indices = []
                index = 0
                for j in nums:
                    if j != 0:
                        prod2 *= j
                    else:
                        zero_indices.append(index)
                    index += 1
                if len(zero_indices) > 1:
                    return answer
                else:
                    answer[zero_indices[0]] = prod2
                    return answer
                    
            
        return [prod / i for i in nums]
        
