#include <iostream>

using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int up = d-b;
    if (b > d || (c - a > up && c >= a)) {
        cout << -1 << '\n';
        return;
    }
    if (c < a)
        cout << a-c+up*2;
    else cout << up-(c-a)+up;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}