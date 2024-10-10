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

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    set<ll> seen;
    seen.insert(0);
    ll odd = 0;
    ll even = 0;
    for (ll i = 0; i < n; i++){
        if (i % 2 == 0){
            odd += a[i];
        }
        else even += a[i];
        if (seen.find(odd-even) != seen.end()){
            cout << "YES\n";
            return;
        }
        seen.insert(odd-even);
    }
    
    cout << "NO\n";
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