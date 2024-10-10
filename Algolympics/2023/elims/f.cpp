#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;
typedef unsigned long long ull;

ull minCost(int starIndex, vector<int>& starByCost, vector<vector<pair<int, int>>>& starByRequiredStars, vector<ull>& dp){
    if (dp[starIndex] != -1) return dp[starIndex];

    ull fromScratchCost = starByCost[starIndex];
    ull viaReqStarsCost = 0;
    bool hasReqStars = false;
    for (auto& reqStars : starByRequiredStars[starIndex]){
        hasReqStars = true;
        viaReqStarsCost += minCost(reqStars.first, starByCost, starByRequiredStars, dp) * reqStars.second;
    }
    
    if (hasReqStars)
        dp[starIndex] = min(fromScratchCost, viaReqStarsCost);
    else dp[starIndex] = fromScratchCost;

    return dp[starIndex];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    unordered_map<string, int> starByIndex;
    vector<int> starByCost(n);
    vector<vector<pair<int, int>>> starByRequiredStars(n, vector<pair<int, int>>());

    for (int i = 0; i < n; i++){
        string star;
        int cost;
        cin >> star >> cost;
        starByIndex[star] = i;
        starByCost[i] = cost;
    }
    for (int i = 0; i < r; i++){
        string resStar, reqStar;
        int reqAmt;
        cin >> resStar >> reqStar >> reqAmt;
        starByRequiredStars[starByIndex[resStar]].push_back({starByIndex[reqStar], reqAmt});
    }

    vector<ull> dp(n, -1);
    for (int i = 0; i < q; i++){
        string star;
        cin >> star;
        cout << minCost(starByIndex[star], starByCost, starByRequiredStars, dp) << '\n';
    }
}