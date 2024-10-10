#include <iostream>
#include <cmath>

using namespace std;

int rcWay(int n, int k, int i){
    if (n < 0) return 0;
    if (i == k) return n >= 0;
    if (i == 30) return n >= 0;
    
    int take = rcWay(n - pow(2, i), k, i+1);
    int skip = rcWay(n, k, i+1);
    return take + skip;
}

void solve(){
    int n, k;
    cin >> n >> k;

    cout << rcWay(n, k, 0) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}