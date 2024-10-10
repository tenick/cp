#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool canObtain[5001];

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    if (nums[0] != 1){
        cout << "NO\n";
        return;
    }
    memset(canObtain, 0, sizeof canObtain);
    canObtain[1] = true;
    bool possible = true;
    for (int i = 1; i < n; i++){
        if (!canObtain[nums[i]]){
            possible = false;
            break;
        }
        for (int j = 5000; j > nums[i]; j--){
            canObtain[j] |= canObtain[j - nums[i]];
        }
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
