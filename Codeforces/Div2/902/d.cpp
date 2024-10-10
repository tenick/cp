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

const int MOD = 998244353;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    vector<int> maxa(n);
    for (int i = 0; i < n; i++){
        int maxnum = 0;
        for (int j = i; j < n; j+=i+1){
            maxnum = max(maxnum, arr[j]);
        }
        maxa[i] = maxnum;
    }
    sort(maxa.begin(), maxa.end());
    
    int pwr = 1;
    int ans = 0;
    for (int i = 0; i < n; i++){
        pwr %= MOD;
        ans += (pwr * 1ll * maxa[i]) % MOD;
        ans %= MOD;

        pwr *= 2;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}