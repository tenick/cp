#include <iostream>

using namespace std;

typedef unsigned long long ull;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;

    ull prev1 = 3;
    ull prev2 = 2;
    if (n == 0) {
        cout << prev2 << '\n';
        return;
    }
    if (n == 1){
        cout << prev1 << '\n';
        return;
    }

    ull ans = 0;
    for (int i = 2; i <= n; i++){
        //cout << prev2 << " " << prev1 << " " << ans << '\n'; // Sn = n * (2 * a1 + (n - 1) * d) / 2
        ans = 2 * prev1 - prev2 + 2;
        prev2 = prev1;
        prev1 = ans;
    }   
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    while (t--){
        solve();
    }
}