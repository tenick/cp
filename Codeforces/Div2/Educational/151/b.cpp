#include <iostream>

using namespace std;

typedef long long ll;

void solve(){
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    
    ll xPathB = xb - xa;
    ll yPathB = yb - ya;

    ll xPathC = xc - xa;
    ll yPathC = yc - ya;

    ll ans = 1;
    // check if same horizontal direction
    if ((xPathB < 0 && xPathC < 0) ||
        (xPathB > 0 && xPathC > 0))
        ans += min(abs(xPathB), abs(xPathC));

    // check if same vertical direction 
    if ((yPathB < 0 && yPathC < 0) ||
        (yPathB > 0 && yPathC > 0))
        ans += min(abs(yPathB), abs(yPathC));

    // not same in any direction
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