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

template <typename T> bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline T bit_toggle(T number, int pos) {
    return number ^ ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline T bit_set(T number, int pos) {
    return number | ((T)1 << pos);
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool found1 = false;
    bool found2 = false;
    int clockwise = a;
    while (clockwise != b) {
        if (clockwise == c) found1 = true;
        if (clockwise == d) found2 = true;
        clockwise++;
        if (clockwise == 13) clockwise = 1;
    }

    bool found3 = false;
    bool found4 = false;
    clockwise = b;
    while (clockwise != a) {
        if (clockwise == c) found3 = true;
        if (clockwise == d) found4 = true;
        clockwise++;
        if (clockwise == 13) clockwise = 1;
    }

    if ((found1 && found2) || (found3 && found4)) cout << "NO\n";
    else cout << "YES\n";
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