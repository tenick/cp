#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> vamps(n);
    for (int& v : vamps) cin >> v;

    ll minStrength = vamps[0];
    for (int v : vamps) minStrength &= v;
    if (minStrength != 0) {
        cout << 1 << '\n';
        return;
    }
    ll currStrength = vamps[0];
    int maxGroups = 0;
    for (int i = 0; i < vamps.size(); i++){
        currStrength &= vamps[i];
        if (currStrength == minStrength){
            maxGroups++;
            if (i < vamps.size()-1)
                currStrength = vamps[i+1];
        }
    }

    cout << maxGroups << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}