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

string s;
const int MOD = 998'244'353;
void solve(){
    cin >> s;

    char curr = s[0];
    ll len = 0;
    vector<ll> altParts;
    for (char c : s){
        if (c == curr){
            len++;
        }
        else {
            altParts.push_back(len);
            curr = c;
            len = 1;
        }
    }
    altParts.push_back(len);

    ll ans = s.size() - altParts.size();
    ll ans2 = 1;
    for (ll l : altParts){
        ans2 = (ans2 * l) % MOD;
    }
    for (ll i = 2; i <= s.size() - altParts.size(); i++){
        ans2 = (ans2 * i) % MOD;
    }

    cout << ans << " " << ans2 << '\n';
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