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

bool isPossible(int len, string s) {
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0'){
            if (s.size() - i < len) return false;
            for (int j = i; j < i + len; j++){
                s[j] = (s[j] == '0' ? '1' : '0');
            }
        }
    }
    return true;
}

int binSearchEven(int n, string& s){
    int l=2, r=n/2;
    int res = 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (isPossible(mid*2, s)) {
            res = max(res, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (isPossible(l * 2, s)) res = max(res, l);
    return res * 2;
}

int binSearchOdd(int n, string& s){
    int l=1, r=n/2;
    if (n % 2 == 1)
        r++; 

    int res = 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (isPossible(mid*2 - 1, s)) {
            res = max(res, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (isPossible(l * 2 - 1, s)) res = max(res, l);
    return res * 2 - 1;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int evenAns = -1;
    if (isPossible(2, s))
        evenAns = binSearchEven(n, s);
    cout << max(evenAns, binSearchOdd(n, s)) << '\n';
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