#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    ll cond = nums[n-1] - nums[0];

    vector<ll> negs;
    vector<ll> pos;
    int zeroes = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] > 0) pos.push_back(nums[i]);
        else if (nums[i] < 0) negs.push_back(nums[i]);
        else zeroes++;
    }
    reverse(negs.begin(), negs.end());

    vector<ll>& main = negs.size() > pos.size() ? negs : pos;
    vector<ll>& aux = negs.size() > pos.size() ? pos : negs;
    vector<ll> ans;
    bool possible = true;
    ll sum = 0;
    int auxi = 0;
    for (int i = 0; i < main.size(); i++){
        if (abs(sum) >= cond){
            possible = false;
            break;
        }
        while (auxi < aux.size() && abs(sum + main[i]) >= cond){
            sum += aux[auxi];
            ans.push_back(aux[auxi]);
            auxi++;
        }
        sum += main[i];
        ans.push_back(main[i]);
    }
    for (; auxi < aux.size(); auxi++) {
        sum += aux[auxi];
        ans.push_back(aux[auxi]);
    }
    for (int i = 0; i < zeroes; i++) ans.push_back(0);

    if (abs(sum) >= cond)
        possible = false;

    if (possible){
        cout << "Yes\n";
        for (int i : ans) cout << i << " ";
        cout << '\n';
    }
    else cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}