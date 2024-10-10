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
    ll n;
    cin >> n;
    ll curr = 1;
    ll currMax = 1;
    while (curr * curr * curr <= n){
        ll num = curr * curr * curr;
        vector<int> nums;
        while (num != 0){
            nums.push_back(num % 10);
            num/=10;
        }
        bool isPal = true;
        for (int i = 0; i < nums.size()/2; i++){
            if (nums[i] != nums[nums.size()-i-1]){
                isPal = false;
                break;
            }
        }
        if (isPal) {
            currMax = curr;
        }
        curr++;
    }
    cout << currMax * currMax * currMax << '\n';
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