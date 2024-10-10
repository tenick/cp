#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<ull> arr(n);
    vector<ull> ps(n);
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        ps[i] = arr[i];
        if (i > 0) ps[i] += ps[i-1];
    }

    for (int i = 0; i < q; i++){
        ull l, r, k;
        cin >> l >> r >> k;
        
        ull total = ps[n-1] - ps[r-1];
        total += l > 1 ? ps[l-2] : 0;
        ull rangeTotal = (r - l + 1) * k;
        if ((total % 2 == 1 && rangeTotal % 2 == 0) || (total % 2 == 0 && rangeTotal % 2 == 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}