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

// use pos = 0, if you want to work with 1st bit of given number
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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& i : p) cin >> i;
    int ans = 0;
    vector<int> removals;
    int streak = 1;
    bool rising = p[1] > p[0];
    for (int i = 1; i < n; i++) {
        if (p[i] > p[i-1]) { // rising
            if (!rising)
                streak = 1;
            streak++;
            if (streak > 2)
                removals.push_back(i);
        }
        else {
            if (rising)
                streak = 1;
            streak++;
            if (streak > 2)
                removals.push_back(i);
        }
        rising = p[i] > p[i-1];
    }
    cout << n - removals.size() << '\n';
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < removals.size() && removals[j]-1 == i) {
            j++;
            continue;
        }
        cout << p[i] << ' ';
    }
    cout << '\n';
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