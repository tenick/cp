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
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    vector<ll> b(n);
    for (ll& i : b) cin >> i;
    vector<pair<ll, ll>> costByCnt(n);
    for (ll i = 0; i < n; i++){
        costByCnt[i] = {b[i], a[i]};
    }
    sort(costByCnt.begin(), costByCnt.end());
    ll total = p;
    ll skipend = n;
    ll added = 0;
    for (auto& ba : costByCnt){
        //cout << ba.first << ", " << ba.second << '\n';
        if (added + 1 >= skipend) break;
        added++;

        if (ba.first >= p){
            total += (skipend - added) * p;
            break;
        }
        
        total += ba.first;

        total += ba.first * (min(skipend - added, ba.second) - 1);

        skipend = skipend - ba.second + 1;
    }
    cout << total << '\n';
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