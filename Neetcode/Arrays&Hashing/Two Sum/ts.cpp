#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> t;
    
    for (int i = 0; i < nums.size(); i++){
        if (t.find(nums[i]) == t.end())
            t[nums[i]] = i;
        int remaining = target - nums[i];
        if (t.find(remaining) != t.end() && i != t[remaining]){
            return {i, t[remaining]};
        }
    }
    return {};
}

int main(){
    std::vector<int> nums = {2,7,11,15};
    std::vector<int> result = twoSum(nums, 9);

    for (int i : result){
        std::cout << i << ',';
    }
}