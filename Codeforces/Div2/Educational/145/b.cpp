#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve(){
    ull chips;
    cin >> chips;
    // cout << (ull)(sqrt(chips-1)) << '\n'; 
    ull l=0,r=1e9;
    while (l < r){
        ull cost = (l+r)/2;
        if ((cost + 1) * (cost + 1) < chips) l = cost + 1;
        else r = cost;
    }
    cout << l << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}