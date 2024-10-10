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
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int curr; cin >> curr;
        arr.push_back({curr, i+1});
    }
    sort(arr.begin(), arr.end(), greater<>());
    
    bool niceIndsExist = false;
    vector<int> niceInds;
    // case 1, remove biggest int
    ll sum2 = 0;
    for (int i = 1; i < n; i++)
        sum2 += arr[i].first;
    if ((ll)arr[1].first * 2ll == sum2) 
        niceInds.push_back(arr[0].second);

    // case 2, check other indices
    ll sum = 0;
    for (auto p : arr) 
        sum += p.first;
    for (int i = 1; i < n; i++)
        if ((ll)arr[0].first * 2ll == (sum - arr[i].first))
            niceInds.push_back(arr[i].second);

    cout << niceInds.size() << '\n';
    for (int nice : niceInds)
        cout << nice << ' ';
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