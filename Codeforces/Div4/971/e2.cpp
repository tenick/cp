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

ll arsum(ll n) {
  return (n+1)*n/2;
}
ll calcans(ll n, ll k, ll i) {
  ll sk = arsum(k - 1);
  ll s1 = arsum(k + i);
  ll s2 = arsum(k + n - 1) - s1;
  s1 -= sk;
  return abs(s1 - s2);
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ull n, k;
  cin >> n >> k;
  ll sn = arsum(k + n - 1), sk = arsum(k - 1);
  ll a = 1, b = 2 * k + 1, c = k * (k + 1) - sn - sk;
  ll x = round((sqrt(b*b - 4ull * a * c)-b)/2);
  cout << calcans(n, k, x) << '\n';
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

