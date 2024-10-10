#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool possible = true;
    for (int i = n-2; i >= 0; i--){
        if (a[i] > a[n-1] || b[i] > b[n-1]){
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
        if (a[i] > a[n-1] || b[i] > b[n-1]){
            possible = false;
            break;
        }
    }
    if (possible) cout << "YES\n";
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