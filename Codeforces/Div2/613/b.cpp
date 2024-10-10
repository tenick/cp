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
bool possible(vector<int>& arr) {
    ll currsum = 0;
    for (int i : arr) {
        currsum += i;
        if (currsum == 0) return true;
    }
    currsum = 0;
    for (int i = arr.size()-1; i >= 0; i--) {
        currsum += arr[i];
        if (currsum == 0) return true;
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    ll sum = 0;
    for (int i : arr) sum += i;
    ll currsum = 0;
    ll maxsum = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int val = arr[i];
        currsum += val;
        maxsum = max(maxsum, currsum);
        if (currsum <= 0) {
            currsum = 0;
            start = i;
        }
    }
    
    if (sum > maxsum) {
        cout << "YES\n";
        return;
    }
    if (sum == maxsum){
        if (start == 0) {
            if (possible(arr)) cout << "NO\n";
            else cout << "YES\n";
        }
        else cout << "NO\n";
    }
    else cout << "NO\n";
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