#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class DSU {
public:
    /// @brief Initially, there are `n` sets created for each node `[0, n)`, with the node themselves as the representative node of the sets, in `_arr`. Let `u` be some node in some set in `_arr`.
    ///        If `_arr[u]` is negative, then `u` is the representative node of the set with size `abs(_arr[u])` (size is stored as a negative number, to differentiate with non-negative integer pointers,
    ///        this avoids creating another array for storing sizes).
    ///        Else, `_arr[u]` is a non-negative pointer to another node in the same set as `u` which eventually leads to the representative node of the set, after following the chain of pointers.
    vector<int> _arr;

    /// @brief Find's parent of `node`; applies path compression along the way
    /// @param node given node
    /// @return Parent node of `node`
    int FindParent(int node) {
        if (_arr[node] < 0)
            return node;
        return _arr[node] = FindParent(_arr[node]);
    }
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
        if (u_size > v_size) // prefer to make parent with higher size the new parent of both u and v
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
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int& i : arr){ cin >> i; i--;};
  DSU dsu = DSU(n);
  vector<int> degs(n);
  vector<set<int>> cnts(n);
  for (int i = 0; i < n; i++) {
    cnts[i].insert(arr[i]);
    cnts[arr[i]].insert(i);
    dsu.UnionBySize(i, arr[i]);
  }
  for (int i = 0; i < n; i++)
    degs[i] = cnts[i].size();
  map<int, set<int>> parByNodes;
  for (int i = 0; i < n; i++) {
    int par = dsu.FindParent(i);
    if (parByNodes.find(par) == parByNodes.end())
      parByNodes[par] = set<int>();
    if (par == i)
      continue;
    parByNodes[par].insert(i);
  }
  int setWOnes = 0;
  for (auto& kvp : parByNodes) {
    bool hasOne = false;
    for (auto i : kvp.second){
      if (degs[i] == 1) hasOne = true;
    }
    setWOnes += hasOne;
  }
  int hi = parByNodes.size();
  int lo = hi - max(0, setWOnes - 1);
  cout << lo << " " << hi << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
