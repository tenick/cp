#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll reqDays(vector<int>& arr, ll mid){
    auto iter = lower_bound(arr.begin(), arr.end(), mid);
    if (iter == arr.end())
        iter--;
    int ind = iter - arr.begin();
    
    ll days = 0;
    while (ind >= 0) {
        if (arr[ind] > mid) {
            ind--;
            continue;
        }
        ll x = (mid - arr[ind]) / (ind + 1) + 1;
        days += x;
        mid -= (ind + 1) * x;
        ind--;
    }
    return days;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    if (a[0] != 1) {
        cout << 1 << '\n';
        return;
    }

    ll l=0,r=1e11;
    while (l < r) {
        ll mid = (l + r) / 2;
        // how many days are needed to remove all elements from 1 to mid?
        ll daysNeeded = reqDays(a, mid);
        if (daysNeeded > k){
            r = mid;
        }
        else l = mid+1;
    }
    cout << l << '\n';
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