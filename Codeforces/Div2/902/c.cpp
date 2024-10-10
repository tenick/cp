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
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 3) {
        cout << 0 << '\n';
        return;
    }
    if (k == 1){
        cout << k << '\n';
        return;
    }
    if (k == 2) {
        if (m <= n) cout << m;
        else {
            cout << (m / n) + n - 1;
        }
        cout << '\n';
        return;
    }
    if (k == 3) {
        if (m <= n || n == 1)
            cout << 0;
        else {
            cout << (m - n) - ((m - n) / n);
        }

        cout << '\n';
        return;
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