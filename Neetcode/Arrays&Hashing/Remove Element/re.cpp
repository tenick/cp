#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int curr = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == val)
            curr++;
        else
            nums[i - curr] = nums[i];
    }
    return nums.size() - curr;
}

int main(){
    std::vector<int> nums {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k = removeElement(nums, val);

    for (int i = 0; i < k; i++){
        std::cout << nums[i] << ',';
    }
}