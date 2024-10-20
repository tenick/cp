#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] <= nums[i+1])
                continue;
            int newval = nums[i];
            if (nums[i] % 2 == 0) {
                newval = nums[i] / (nums[i] / 2);
            }
            else {
                for (int j = 3; j <= sqrt(nums[i]); j+=2) {
                    if (nums[i] % j == 0) {
                        newval = nums[i] / (nums[i] / j);
                        break;
                    }
                }
            }
            if (newval > nums[i+1])
                return -1;
            nums[i] = newval;
            ans++;
        }
        return ans;
    }
};
int main(){
}
