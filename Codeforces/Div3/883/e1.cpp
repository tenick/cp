#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

void solve(){
    ull n;
    cin >> n;
    ull k = 2;
    while (true){
        ull exp = 1;
        ull curr = 1;
        while (curr < n){
            curr += pow(k, exp);
            if (curr > n) break;
            exp++;
        }
        if (exp >= 3 && curr == n){
            cout << "YES\n";
            return;
        }
        if (exp < 3) break;
        k++;
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}