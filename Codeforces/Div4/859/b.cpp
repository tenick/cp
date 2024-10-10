#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }

    int m=0,b=0;
    for (int i : c){
        if (i % 2 == 0) m += i;
        else b += i;
    }
    if (m > b) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}