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

void cnt(int node, vector<int>& whites, vector<int>& blacks, const string& colors, const vector<vector<int>>& parentsByChild) {
    whites[node] += colors[node] == 'W';
    blacks[node] += colors[node] == 'B';
    if (parentsByChild[node].empty())
        return;
    for (int child : parentsByChild[node]) {
        cnt(child, whites, blacks, colors, parentsByChild);
        whites[node] += whites[child];
        blacks[node] += blacks[child];
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for (int& i : arr) cin >> i;
    string s;
    cin >> s;
    vector<vector<int>> parentsByChild(n);
    for (int i = 0; i < n-1; i++){
        parentsByChild[arr[i]-1].push_back(i+1);
    }
    vector<int> whites(n);
    vector<int> blacks(n);
    cnt(0, whites, blacks, s, parentsByChild);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += whites[i] == blacks[i];
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