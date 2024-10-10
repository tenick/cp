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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    ll sum = 0;
    for (ll& i : a) sum += i;

    if (sum % n != 0) cout << "NO\n";
    else {
        ll req = sum / n;
        ll missing = req - a[n-1];
        if (missing < 0) {
            cout << "NO\n";
            return;
        }

        for (int i = n-2; i >= 0; i--){
            if (a[i] <= missing){
                missing -= a[i];
                a[i] = 0;
            }
            else { // a[i] > missing
                if (a[i] - missing > req){
                    cout << "NO\n";
                    return;
                }
                a[i] -= missing;
                missing = 0;
            }
            missing += req - a[i];
        }

        if (missing != 0) cout << "NO\n";
        else cout << "YES\n";
    }
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