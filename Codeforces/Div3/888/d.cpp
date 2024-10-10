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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<ll> ps(n-1);
    for (ll& i : ps) cin >> i;

    vector<bool> seen(n);


    ll pref = 0;
    ll anomaly = -1;
    for (int i = 0; i < n-1; i++){
        ll val = ps[i] - pref;
        if (val > n){
            if (anomaly != -1){
                cout << "NO\n";
                return;
            }
            anomaly = val;
        }
        else {
            if (seen[val-1]){
                if (anomaly != -1){
                    cout << "NO\n";
                    return;
                }
                anomaly = val;
            }
            seen[val-1] = true;
        }

        pref = ps[i];
    }

    if (anomaly == -1){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (!seen[i]) cnt++;
        }

        if (cnt != 1){
            cout << "NO\n";
            return;
        }
    }
    else {
        int cnt = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++){
            if (!seen[i]){
                cnt++;
                sum += (ll)(i+1);
            }
        }

        if (cnt != 2 || sum != anomaly){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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