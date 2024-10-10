#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int rcWay(int i, int totalNums, int currMex, vector<int>& newMex, vector<int>& cnt, vector<vector<int>>& memo){
    if (memo[i][currMex] != -1) return memo[i][currMex];
    if (i == 0) {
        int final = newMex[i] + currMex * (cnt[i] - 1);
        //cout << "base to add: " << final << '\n';
        return memo[i][currMex] = final;
    }

    // take
    int toAdd = newMex[i] + currMex * (cnt[i] - 1);
    //cout << "to add at index: " << i << " = " << toAdd << " | new totalNums = " << totalNums - cnt[i] << '\n';
    int ans1 = rcWay(i - 1, totalNums - cnt[i], newMex[i], newMex, cnt, memo) + toAdd;

    // skip
    //cout << "skipping at index: " << i << "\n\n";
    int ans2 = rcWay(i - 1, totalNums, currMex, newMex, cnt, memo);

    return memo[i][currMex] = min(ans1, ans2);
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    map<int, int> freq;
    for (int i : a){
        if (freq.find(i) == freq.end()) freq[i] = 0;
        freq[i]++;
    }
    vector<int> newMex;
    vector<int> cnt;
    for (auto& kvp : freq){
        newMex.push_back(kvp.first);
        cnt.push_back(kvp.second);
    }

    int currMex = 0;
    for (int i = 0; i < newMex.size(); i++){
        if (newMex[i] == currMex) currMex++;
    }
    if (currMex == 0){
        cout << 0 << '\n';
        return;
    }

    // pick index
    int ind = 0;
    for (int i = cnt.size()-1; i >= 0; i--){
        if (currMex > newMex[i]){
            ind = i;
            break;
        }
    }

    vector<vector<int>> memo(currMex+1, vector<int>(currMex+1, -1));
    cout << rcWay(ind, n, currMex, newMex, cnt, memo) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}
