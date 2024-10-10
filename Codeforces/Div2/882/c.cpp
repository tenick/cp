#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> stands(n);
    for (int& v : stands) cin >> v;

    bool found[256]{};
    found[0] = 1;
    int curr = 0;
    for (int s : stands){
        curr ^= s;
        found[curr] = 1;
    }

    for (int i = 255; i >= 0; i--){
        for (int j = 0; j < 256; j++){
            if (!found[j]) continue;
            if (found[found[j] ^ i]){
                cout << i << '\n';
                return;
            }
        }
    }
    cout << 0 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}