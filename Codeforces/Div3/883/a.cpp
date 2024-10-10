#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > b[i]) count++;
    }
    cout << count << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}