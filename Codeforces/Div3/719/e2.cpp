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

// idea: The median minimizes the sum of absolute deviations
// Time complexity: 3 pass O(n)
// Space complexity: O(1)

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sheepsCnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') sheepsCnt++;
    }
    int medianSheepAt = sheepsCnt / 2 + 1;
    int medianSheepInd = -1;
    int leftSheeps = 0;
    int rightSheeps = 0;
    bool inLeft = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (sheepsCnt == medianSheepAt) {
                medianSheepInd = i;
                inLeft = false;
            }
            else {
                if (inLeft) leftSheeps++;
                else rightSheeps++;
            }
            sheepsCnt--;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (leftSheeps != 0) {
                ans += medianSheepInd - i - leftSheeps;
                leftSheeps--;
            }
            else {
                ans += i - medianSheepInd - rightSheeps;
                rightSheeps--;
            }
        }
    }
    cout << ans << '\n';
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