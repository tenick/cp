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
    ll a, b, r;
    cin >> a >> b >> r;

    for (ll i = 63; i >= 0; i--){
        ll curr = 1ll << i;
        ll ac = a & curr;
        ll bc = b & curr;

        if (curr <= r && ac != bc){
            if (a > b){
                a &= ~curr;
                b |= curr;
            }
            else{
                a |= curr;
                b &= ~curr;
            }
            r &= ~curr;
        }
    }
    cout << abs(a - b) << '\n';
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