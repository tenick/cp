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

template <typename T> inline T iceil(T a, T b) {
  return (a + b - 1) / b;
}

#define MOD_ANSWER
#ifdef MOD_ANSWER
constexpr int MOD = 1e9 + 7;
#endif
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2){
      res *= a;
      #ifdef MOD_ANSWER
      res %= MOD;
      #endif
    } 
    a *= a;
    #ifdef MOD_ANSWER
    a %= MOD;
    #endif
    b /= 2;
  }
  return res;
}

#define ONLINE_JUDGE
struct btree {
  btree* left;
  btree* right;
  int val;
  btree(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

void attach(btree* head, int val, const vector<vector<int>>& adj) {
  if (adj[head->val][val]) {
    if (head->right == nullptr) {
      head->right = new btree(val);
    }
    else attach(head->right, val, adj);
  }
  else {
    if (head->left == nullptr) {
      head->left = new btree(val);
    }
    else attach(head->left, val, adj);
  }
}

void inorder(btree* head) {
  if (head == nullptr)
    return;
  inorder(head->left);
  cout << head->val+1 << ' ';
  inorder(head->right);
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (auto& row : adj) {
    string s;
    cin >> s;
    for (char c : s) row.push_back(c - '0');
  }
  btree* head = new btree(0);  
  for (int i = 1; i < n; i++) {
    attach(head, i, adj);
  }
  inorder(head);
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

