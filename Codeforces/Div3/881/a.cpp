#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> elems(n);
    for(int& i : elems) cin >> i;
    sort(elems.begin(), elems.end());

    int ans = 0;
    for(int i = 0; i < n/2; i++){
        int opp = n-1-i;
        ans += elems[opp] - elems[i];
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}