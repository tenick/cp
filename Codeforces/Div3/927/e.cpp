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

int rcWay(int i, int add, string& s, string& newstr){
    if (i == s.size()) return 0;
    int val = (s[i] - '0') + add;
    val += rcWay(i+1, val, s, newstr);
    if (i != 0) {
        newstr.push_back((val%10) + '0');
        val /= 10;
    }
    else {
        while (val != 0){
            newstr.push_back((val % 10) + '0');
            val/=10;
        }
    }
    return val;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string newstr;
    rcWay(0, 0, s, newstr);
    reverse(newstr.begin(), newstr.end());
    int trailingzeros = 0;
    for (char i : newstr) {
        if (i == '0') trailingzeros++;
        else break;
    }
    cout << newstr.substr(trailingzeros) << '\n';
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