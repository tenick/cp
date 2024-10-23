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
template <typename T> inline bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline void bit_toggle(T& number, int pos) {
    number ^= ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline void bit_set(T& number, int pos) {
    number |= ((T)1 << pos);
}

void solve(){
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    bool allc = true;
    int ccnt = 0;
    for (int i = 0; i < n-1; i++) ccnt += s[i] == c;
    if (ccnt == n-1) {
        if (s[n-1] == c)
            cout << 0;
        else
            cout << 1 << '\n' << n-1;
    }
    else if (s[n-1] == c) cout << 1 << '\n' << n;
    else  {
        // try to check if 1 is possible
        bool possible = false;
        for (int i = 2; i <= n; i++) {
            int currind = i;
            bool pos = true;
            while (pos && currind <= n) {
                pos &= s[currind-1] == c;
                currind += i;
            }
            if (pos) {
                possible = true;
                cout << 1 << '\n' << i;
                break;
            }
        }
        if (!possible)
            cout << 2 << '\n' << n << " " << n-1;
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