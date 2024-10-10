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

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int l=1e9,r=0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        char c = s[i];
        if (c == 'B'){
            l = min(l, i);
            r = max(r, i);
        }
    }
    cout << r - l + 1 << '\n';
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