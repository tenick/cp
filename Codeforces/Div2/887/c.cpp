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
    ull n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    if (a[0] > 1){
        cout << 1 << '\n';
        return;
    }

    ull prev = 0;
    ull curr = 0;
    ull xtra = 0;
    ull ans = 1;
    for (int i = 0; i < n; i++){
        if (k == 0) break;
        if (a[i] - 1 == prev){
            curr++;
            prev = a[i];
        }
        else {
            ull between = a[i] - prev - 1;
            ull tosub = min(xtra, between);
            between -= tosub;
            xtra -= tosub;

            ull days = min(k, between / curr + (between % curr != 0));
            k -= days;
            ans += days * curr;
            
            if (days * curr != 0)
                xtra = days * curr - between;
            curr++;
            prev = a[i];
        }
    }

    cout << ans + k * curr << '\n';
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