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
    ll n, m;
    cin >> n >> m;

    if (n % m == 0){
        cout << 0 << '\n';
        return;
    }
    double ans = (double)(n % m) / m;

    // multiply by 2^32
    ll e32 = 1ll * 1 << 32;
    ans *= e32;
    ll cnt = 0;
    ll curr = 1;
    for (int i = 1; i <= 32; i++){
        curr *= 2;
        e32 >>= 1;
        if (e32 <= ans){
            cnt += m / curr * (curr - 1);
            ans -= e32;
        }
    }
    cout << (ans == 0 ? cnt : -1) << '\n';
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