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
    map<int, int> mp;
    int mex2 = 0;
    vector<bool> found(n);
    for (int i : a){
        if (mp.find(i) == mp.end()) mp[i] = 0;
        found[i] = true;
        while (mex2 < n && found[mex2])
            mex2++;
        mp[i]++;
    }
    for (int i = 0; i < n; i++)
        found[i] = false;

    int mex1 = 0;
    for (int i = 0; i < n-1; i++){
        int num = a[i];

        found[num] = true;
        while (mex1 < n && found[mex1])
            mex1++;
        
        mp[num]--;
        if (mp[num] == 0) {
            mp.erase(num);
            mex2 = min(mex2, num);
        }
        if (mex1 == mex2){
            cout << 2 << '\n';
            cout << 1 << " " << (i+1) << '\n';
            cout << i + 2 << " " << n << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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