#include <iomanip>
#include <iostream>
#include <sstream>
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

// #define ONLINE_JUDGE

ll concatll(ll a, ll b) {
  string astr = to_string(a);
  string bstr = to_string(b);
  string abstr = astr + bstr;
  return stoll(abstr);
}
bool rcway(int i, ll curr, ll target, vector<ll>& nums) {
  if (i == nums.size())
    return curr == target;
      
  // add
  bool res1 = rcway(i+1, curr == -1 ? nums[i] : nums[i] + curr, target, nums);
  // multiply
  bool res2 = rcway(i+1, curr == -1 ? nums[i] : nums[i] * curr, target, nums);
  // concatenate
  bool res3 = rcway(i+1, curr == -1 ? nums[i] : concatll(curr, nums[i]), target, nums);

  return res1 | res2 | res3;
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  string line;
  ll ans = 0;
  while (getline(cin, line)) {
    if (line.empty()) 
      break;
    int colonpos = line.find(':');
    string res = line.substr(0, colonpos);
    ll val = stoll(res);
    string numsstr = line.substr(colonpos+2);
    istringstream iss(numsstr);
    vector<ll> nums;
    ll num;
    while (iss >> num) {
      nums.push_back(num);
    }

    if (rcway(0, -1, val, nums)) 
      ans += val;
  }

  cout << ans << '\n';
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

