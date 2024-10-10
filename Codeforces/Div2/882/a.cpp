#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> villagers(n);
    for (int& v : villagers) cin >> v;
    vector<int> toConsider;
    for (int i = 1; i < villagers.size(); i++){
        toConsider.push_back(abs(villagers[i] - villagers[i-1]));
    }
    int ans = 0;
    sort(toConsider.begin(), toConsider.end());

    int i = 0;
    while (k != n){
        ans += toConsider[i];
        i++;
        k++;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}