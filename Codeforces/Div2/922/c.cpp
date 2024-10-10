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

    for (int i = 63; i >= 0; i--){
        ll curr = 1ll << i;
        if (curr > r) continue;

        ll ac = a & curr;
        ll bc = b & curr;
        if (ac != bc){
            ll tempa = a ^ curr;
            ll tempb = b ^ curr;
            if (abs(tempa - tempb) < abs(a - b)){
                a = tempa;
                b = tempb;
                r -= curr;
            }
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