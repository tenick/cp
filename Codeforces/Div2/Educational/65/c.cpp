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

class DSU {
    vector<int> _arr;
    /// @brief Find's parent of `node`; applies path compression along the way
    /// @param node given node
    /// @return Parent node of `node`
    int FindParent(int node) {
        if (_arr[node] < 0)
            return node;
        return _arr[node] = FindParent(_arr[node]);
    }
public:
    DSU(int n) : _arr(n, -1) {}

    /// @brief Applies `Union By Size` operation of DSU on 2 given nodes `u` and `v`; call's `FindParent` internally, thus applying path compression along the way
    /// @param u - 1st given node
    /// @param v - 2nd given node
    /// @return `false` if both nodes are already in the same set, `true` if merged 2 different sets of `u` and `v` successfully
    bool UnionBySize(int u, int v) {
        int u_par = FindParent(u);
        int v_par = FindParent(v);
        if (u_par == v_par) // u and v are in the same set
            return false;
        
        int u_size = _arr[u_par];
        int v_size = _arr[v_par];
        if (u_size > v_size)
            swap(u_par, v_par);

        _arr[v_par] = u_par;
        _arr[u_par] = u_size + v_size;
        return true;
    }

    /// @brief Gets the size of the set that `node` is in
    /// @param node 
    /// @return returns the size of the set that `node` is in
    int GetSize(int node) {
        if (_arr[node] < 0)
            return abs(_arr[node]);
        return abs(_arr[FindParent(node)]);
    }
};


void solve(){
    int n, m;
    cin >> n >> m;

    DSU dsu = DSU(n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if (k == 0) continue;
        vector<int> peeps(k);
        for (int& j : peeps) cin >> j;

        int parent = peeps[0]-1;
        for (int i = 1; i < k; i++) {
            dsu.UnionBySize(parent, peeps[i]-1);
        }
    }
    for (int i = 0; i < n; i++)
        cout << dsu.GetSize(i) << ' ';
    cout << '\n';
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