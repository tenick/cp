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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    sort (a.begin(), a.end());
    int origInd = n/2;
    if (n % 2 == 0) origInd--;
    int ind = origInd;
    a[ind]++;
    int curr = a[ind];
    int cnt = 0;
    for (int i = ind; i < n; i++){
        while (a[i] < a[origInd]) {
            a[i]++;
            cnt++;
        }
    }
    cout << cnt+1 << '\n';
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