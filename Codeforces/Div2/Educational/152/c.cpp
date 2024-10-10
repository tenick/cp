#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n, m;
    string s;
    cin >> n >> m >> s;
    
    vector<int> lf(n), rg(n);
    lf[0] = -1;
    for (int i = 0; i < n; ++i) {
        if (i > 0) lf[i] = lf[i - 1];
        if (s[i] == '0') lf[i] = i;
    }
    rg[n - 1] = n;
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) rg[i] = rg[i + 1];
        if (s[i] == '1') rg[i] = i;
    }

    // for (int i : lf) cout << i << ' ';
    // cout << '\n';
    // for (int i : rg) cout << i << ' ';
    // cout << '\n';

    set<pair<int, int>> changes;
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;

        if (rg[l-1] > lf[r-1]){
            changes.insert({-1,-1});
        }
        else changes.insert({rg[l-1], lf[r-1]});
    }

    cout << changes.size() << '\n';
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