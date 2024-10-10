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

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> j(n);
    for (ll& i : j) cin >> i;
    vector<ll> g(m);
    for (ll& i : g) cin >> i;
    
    ll sumj = 0;
    for (int i : j) sumj += i; 
    ll minj = *min_element(j.begin(), j.end());
    ll maxj = *max_element(j.begin(), j.end());
    ll ming = *min_element(g.begin(), g.end());
    ll maxg = *max_element(g.begin(), g.end());

    ll ans = sumj - minj + max(minj, maxg);
    if (k % 2 == 1){
        cout << ans << '\n';
        return;
    }
    if (k % 2 == 0){
        if (maxg > minj){ // swap occured
            ll currming = m == 1 ? minj : min(ming, minj);
            ans = ans - max(maxg, maxj) + currming;
        }
        else {
            ans = ans - maxj + ming;
        }
        cout << ans << '\n';
        return;
    }
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