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

void cntBipartite(int node, int parent, const vector<vector<int>>& vertexByNeighbors, int& s1, int& s2) {
    s1++;
    for (int neighbor : vertexByNeighbors[node]) {
        if (neighbor == parent) continue;
        cntBipartite(neighbor, node, vertexByNeighbors, s2, s1);
    }
}
void solve(){
    int n;
    cin >> n;
    int cpn = n;
    int ans = 0;
    vector<vector<int>> vertexByNeighbors(n);
    while (--n) {
        int u, v;
        cin >> u >> v;
        vertexByNeighbors[u-1].push_back(v-1);
        vertexByNeighbors[v-1].push_back(u-1);
    }

    int s1 = 0;
    int s2 = 0;
    cntBipartite(0, -1, vertexByNeighbors, s1, s2);
    cout << (ll)s1 * (ll)s2 - cpn + 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}