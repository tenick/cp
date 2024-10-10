#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool containsDuplicate(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (auto it = nums.begin(); it != nums.end() - 1; ++it){
        if (*it == *(it + 1))
            return true;
    }
    return false;
}

int main(){
    std::vector<int> nums = { 2, 1 ,3 };
    std::cout << std::boolalpha << containsDuplicate(nums);
}

