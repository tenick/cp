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
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n,q;
    cin >> n;
    vector<ll> arr(n);
    for (ll& i : arr) cin >> i;
    cin >> q;
    vector<pair<ll, ll>> queries(q);
    for (auto& query : queries){
        ll x, y;
        cin >> x >> y;
        query = {x, y};
    }

    map<ll, int> mp;
    for (ll i : arr) {
        if (mp.find(i) == mp.end()) mp[i] = 0;
        mp[i]++;
    }

    for (auto& query : queries){
        ll x = query.first;
        ll y = query.second;
        for (int i = n-1; i >= 0; i--){
            ll val = arr[i];
            ll pairX = x - val;
            ll pairY = y / val;
            if (y % val != 0 || mp.find(pairX) == mp.end() || mp.find(pairY) == mp.end())
                continue;
            
        }
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