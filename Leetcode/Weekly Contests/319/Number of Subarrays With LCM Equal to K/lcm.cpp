#include <iostream>
#include <vector>
typedef unsigned long long ull;

ull gcd(ull a, ull b){
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int subarrayLCM(std::vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        ull currLCM = nums[i];
        count += currLCM == k;
        for (int j = i + 1; j < nums.size(); j++){
            currLCM = currLCM * nums[j] / gcd(currLCM, nums[j]);
            count += currLCM == k;
        }
    }
    return count;
}

int main(){
    std::vector<int> nums = {3,6,2,7,1};
    int target = 6;
    std::cout << subarrayLCM(nums, target);
}