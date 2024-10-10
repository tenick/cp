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

void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (ll& i : nums) cin >> i;

    ll maxNeg = -1e10;
    bool allNeg = true;

    ll ansEven = 0;
    for (int i = 0; i < n; i+=2){
        allNeg &= nums[i] < 0;
        if (nums[i] < 0) maxNeg = max(maxNeg, nums[i]);
        ansEven += max(0ll, nums[i]);
    }
    ll ansOdd = 0;
    for (int i = 1; i < n; i+=2){
        allNeg &= nums[i] < 0;
        if (nums[i] < 0) maxNeg = max(maxNeg, nums[i]);
        ansOdd += max(0ll, nums[i]);
    }
    cout << (allNeg ? maxNeg : max(ansEven, ansOdd)) << '\n';
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