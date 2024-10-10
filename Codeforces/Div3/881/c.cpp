#include <iostream>

using namespace std;

typedef unsigned long long ull;

void solve(){
    ull n;
    cin >> n;

    ull ans = 0;
    while (n!=0){
        ans += n;
        n/=2;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}