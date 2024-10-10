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

vector<vector<int>> dirs {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

void solve(){
    int n;
    cin >> n;

    bool shift = false;
    int r = 1, c = 1;
    int offset = 0;
    vector<pair<int, int>> ans;
    int minc = 1, maxc = n, minr = 1, maxr = n;
    int orientation = 0;
    while (n--) {
        int currOffset = offset;
        while (currOffset != 0) {
            if (orientation == 0) {
                r++;
                if (r > maxr) {
                    r--;
                    c++;
                    orientation++;
                    minc++;
                }
            }
            else if (orientation == 1) {
                c++;
                if (c > maxc) {
                    c--;
                    r--;
                    orientation++;
                    maxr--;
                }
            }
            else if (orientation == 2) {
                r--;
                if (r < minr) {
                    r++;
                    c--;
                    orientation++;
                    maxc--;
                }
            }
            else if (orientation == 3) {
                c--;
                if (c < minc) {
                    c++;
                    r++;
                    orientation++;
                    minc++;
                }
            }
            if (orientation == 4) orientation = 0;
            currOffset--;
        }
        ans.push_back({r, c});
        offset++;
    }
    for (auto& kvp : ans) {
        cout << kvp.first << " " << kvp.second << "\n";
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