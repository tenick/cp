#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minCost(vector<int>& nums, int k) {
    if (nums.size() == 1) return k;
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

    for (int i = 0; i < nums.size(); i++){
        unordered_map<int, bool> seen;
        for (int j = i; j < nums.size(); j++){
            int num = nums[j];
            int toAdd = j - 1 < 0 ? k : dp[i][j-1];
            if (seen.find(num) == seen.end()){
                seen[num] = false;
            }
            else {
                if (seen[num]) toAdd++;
                else {
                    seen[num] = true;
                    toAdd += 2;
                }
            }
            
            dp[i][j] = toAdd;

            if (j < nums.size() - 1){
                if (dp[j+1][j] == -1) dp[j+1][j] = dp[i][j] + k;
                else dp[j+1][j] = min(dp[j+1][j], dp[i][j] + k);
            }
        }
    }

    // for (int i = 0; i < dp.size(); i++){
    //     for (int j = 0; j < dp[i].size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int ans = dp[nums.size()-1][nums.size()-1];
    for (int i = 0; i < dp.size(); i++){
        ans = min(ans, dp[i][nums.size()-1]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums{2,3,3,3,1,5,5,0,5,3,4,2,1,2,5,1,2,0};
    int k = 5;
    int ans = minCost(nums, k);
    cout << ans << '\n';
}