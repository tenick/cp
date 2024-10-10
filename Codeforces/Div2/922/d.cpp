#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
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

bool possible(ll target, vector<ll>& ps){
    ll blocksum = 0;
    ll removed = 0;
    ll segmax = 0;
    for (int i = 0; i < ps.size(); i++){
        ll prev = i == 0 ? 0 : ps[i-1];
        if (ps[i] >= target){
            blocksum += ps[i] - prev;
            segmax = max(segmax, prev - removed);
            removed = ps[i];
        }
    }
    return max(blocksum, segmax) <= target;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    vector<ll> ps;
    for (int i = 0; i < n; i++){
        ll prev = i == 0 ? 0 : ps[i-1];
        ps.push_back(a[i] + prev);
    }
    ll l=1,r=ps[n-1];
    while (l < r){
        ll mid = (l + r) / 2;
        if (possible(mid, ps))
            r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
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