#include <functional>
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

#define ONLINE_JUDGE

void showstack(stack<int> st) {
  vector<int> res;
  while (!st.empty()) {
    res.push_back(st.top());
    st.pop();
  }
  reverse(res.begin(), res.end());
  for (int i : res) cout << i+1 << ' ';
  cout << '\n';
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n, m;
  cin >> n >> m;
  vector<set<int, greater<>>> nodesByneighbors(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    nodesByneighbors[u-1].insert(v-1);
    nodesByneighbors[v-1].insert(u-1);
  }
  
  vector<bool> visited(n);
  priority_queue<int, vector<int>, greater<>> st;
  st.push(0);
  vector<int> ans;
  while (!st.empty()) {
    // showstack(st);
    int currnode = st.top();
    st.pop();
    if (visited[currnode]) 
      continue;
    // cout << currnode+1 << " not visited yet\n";
    visited[currnode] = true;
    ans.push_back(currnode);
    for (int neighbor : nodesByneighbors[currnode]) {
      st.push(neighbor);
    }
  }
  for (int i : ans) cout << i+1 << ' ';
  cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}

