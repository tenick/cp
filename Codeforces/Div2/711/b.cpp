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
    int n, w;
    cin >> n >> w;
    vector<int> wis(n);
    for (int& i : wis) cin >> i;
    sort(wis.begin(), wis.end());
    reverse(wis.begin(), wis.end());
    set<pair<int, int>> levels; // {remaining space, height}
    // if cant find level which fits the box width, assume there is one element in it such that: {w, currHeight + 1} in levels;
    int currHeight = 0;
    for (int wi : wis) {
        auto res = levels.lower_bound({wi, 1});
        pair<int, int> level = {w, currHeight + 1};
        if (res != levels.end()){
            level = *res;
            levels.erase(level);
        }
        else currHeight++;

        level.first -= wi;
        if (level.first != 0)
            levels.insert(level);
    }
    cout << currHeight << '\n';
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