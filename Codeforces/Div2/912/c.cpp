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

ll forward(int n, vector<int>& arr) {
  ll ss = accumulate(arr.begin()+1, arr.end(), 0ll), ans = arr[0], m = 1;
  for (int i = 1; i < n; i++) {
    if (ss >= 0) m++;
    ans += arr[i] * m;
    ss -= arr[i];
  }
  return ans;
}

// going backwards is faster
ll backward(int n, vector<int>& arr) {
  ll ss = 0, ans = 0;
  for (int i = n-1; i >= 0; i--) {
    ll curr = 1ll * arr[i] * (n - (n - i - 1));
    ans += max(curr, curr - ss);
    ss += arr[i];
  }
  return ans;
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int& i : arr) cin >> i;

  cout << forward(n, arr) << '\n';
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
