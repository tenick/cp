#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    int sum = 1;
    int i = 1;
    bool possible = nums[0] == 1;
    while (i < n && possible && sum <= 2e5){
        possible = nums[i] <= sum;
        sum += nums[i];
        i++;
    }
    if (possible) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}