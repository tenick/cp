#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int subArrs = 1;
    unordered_map<int, int> li;
    unordered_map<int, int> ri;

    int kPos =  find(nums.begin(), nums.end(), k) - nums.begin();

    // get all to the left of k
    int currSum = 0;
    for (int i = kPos - 1; i >= 0; i--) {
        if (nums[i] > k) currSum++;
        else currSum--;        
        li.find(currSum) == li.end() ? li[currSum] = 1 : li[currSum]++;
    }
    // get all to the right of k
    currSum = 0;
    for (int i = kPos + 1; i < nums.size(); i++) {
        if (nums[i] > k) currSum++;
        else currSum--;
        ri.find(currSum) == ri.end() ? ri[currSum] = 1 : ri[currSum]++;
    }

    // count subarrays from left
    for (const auto& sum : li){
        if (sum.first == 0 || sum.first == 1) subArrs += sum.second;
        int targetToOdd = -sum.first;
        if (ri.find(targetToOdd) != ri.end()) subArrs += ri[targetToOdd] * sum.second;
        int targetToEven = -sum.first + 1;
        if (ri.find(targetToEven) != ri.end()) subArrs += ri[targetToEven] * sum.second;
    }

    // count subarrays from right
    for (const auto& sum : ri){
        if (sum.first == 0 || sum.first == 1) subArrs += sum.second;
    }

    return subArrs;
}

int main(){
    vector<int> nums {3, 2, 1, 4, 5};
    nums = {6,7,5,1,12,9,8,10,4,2,3,11};
    int k = 8;
    int ans = countSubarrays(nums, k);
    cout << ans << '\n';
}   