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

vector<vector<int>>fullps{
    {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}, // ones
    {45, 100, 165, 240, 325, 420, 525, 640, 765, 900}, // 9, 19, 29, ..., 99
    {900, 1900, 3000, 4200, 5500, 6900, 8400, 10000, 11700, 13500}, // 99, 199, 299, 399, ..., 999
    {13500, 28000, 43500, 60000, 77500, 96000, 115500, 136000, 157500, 180000}, // 999, 1,999, 2,999, ..., 9,999
    {180000, 370000, 570000, 780000, 1000000, 1230000, 1470000, 1720000, 1980000, 2250000}, // 99,999
    {2250000, 4600000, 7050000, 9600000, 12250000, 15000000, 17850000, 20800000, 23850000, 27000000} // 999,999
};

void solve(){
    int n;
    cin >> n;
    
    vector<int> digits;
    while (n != 0){
        digits.push_back(n % 10);
        n/=10;
    }
    vector<int> digitPart(digits.size(), 0);
    int power = 1;
    for (int i = 1; i < digits.size(); i++){
        digitPart[i] = digits[i-1] * power + digitPart[i-1];
        power *= 10;
    }
    int ans = 0;
    for (int i = digits.size()-1; i >= 0; i--){
        if (digits[i] == 0) continue;
        ans += fullps[i][digits[i]-1];
        ans += digits[i] * (digitPart[i] + 1);
    }
    cout << ans << '\n';
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