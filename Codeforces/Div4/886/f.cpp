#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n+1);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    unordered_map<int, int> frogs;
    for (int i = 0; i < n; i++){
        if (a[i] > n) continue;
        if (frogs.find(a[i]) == frogs.end()) 
            frogs[a[i]] = 0;
        frogs[a[i]]++;
    }

    for (auto& kvp : frogs){
        for (int i = 0; i <= n; i+=kvp.first){
            dp[i]+=kvp.second;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
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