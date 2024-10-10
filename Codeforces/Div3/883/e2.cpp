#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

void solve(){
    ull n;
    cin >> n;

    ull l=2, r=10e18;
    while (l < r) {
        ull mid = (l+r) >> 1;
        if (l==mid) break;

        ull exp = 1;
        ull curr = 1;
        while (curr < n){
            curr += pow(mid, exp);
            if (curr > n) break;
            exp++;
        }

        if (exp >= 3){
            l = mid;
        }
        else {
            r = mid - 1;
        }
        //cout << l << " " << r << " | " << mid << '\n';
    }

    while (true){
        ull exp = 1;
        ull curr = 1;
        while (curr < n){
            curr += pow(l, exp);
            if (curr > n) break;
            exp++;
        }
        if (exp >= 3 && curr == n){
            cout << "YES\n";
            return;
        }
        if (exp < 3) break;
        l++;
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}