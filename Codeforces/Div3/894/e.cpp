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
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> arr(n);
    for (ll& i : arr) cin >> i;

    priority_queue<ll, vector<ll>, std::greater<ll>> pq;
    ll sum = 0;
    ll maxans = 0;
    for (ll i = 1; i <= n; i++){
        ll a = arr[i-1];
        if (a <= 0) continue;
        ll sub = i * d;
        
        sum += a;
        maxans = max(maxans, sum - sub);
        pq.push(a);
        if (pq.size() == m){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << maxans << '\n';
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