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

const int MOD = 1e9 + 7;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    ll sum = 0;
    ll curr = 0;
    for (int i : a){
        sum = max(sum, curr);
        curr += i;
        if (curr < 0){
            curr = 0;
        }
    }
    sum = max(sum, curr);
    ll sub = sum;
    while (k--) {
        sum += sum;
        sum %= MOD;
    }
    for (int i : a) sum += i;
    sum -= sub;
    while (sum < 0) sum += MOD;
    sum = sum % MOD;
    cout << sum << '\n';
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