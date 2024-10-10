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

ll mhd(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve(){
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<pair<ll, ll>> cities(n);
    for (auto& city : cities){
        ll x, y;
        cin >> x >> y;
        city = {x, y};
    }

    ll closestStart = 1e18;
    ll closestEnd = 1e18;
    auto& start = cities[a-1];
    auto& end = cities[b-1];

    ll distStartToEnd = mhd(start.first, start.second, end.first, end.second);
    if (k == 0){
        cout << distStartToEnd;
    }
    else {
        for (int i = 0; i < k; i++){
            auto& city = cities[i];
            closestStart = min(closestStart, mhd(start.first, start.second, city.first, city.second));
            closestEnd = min(closestEnd, mhd(end.first, end.second, city.first, city.second));
        }
        ll ans = min(distStartToEnd, closestStart + closestEnd);
        cout << ans;
    }
    cout << '\n';
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