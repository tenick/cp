#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n" << n << '\n';
        for (int i = 0; i < n; i++)
            cout << "1 ";
        cout << '\n';
        return;
    }
    if (k == 1) {
        cout << "NO\n";
        return;
    }
    if (k == 2 && n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> nums;
    if (n % 2 == 1) {
        n-=3;
        nums.push_back(3);
    }
    while (n != 0){
        n-=2;
        nums.push_back(2);
    }
    cout << nums.size() << '\n';
    for (int i : nums) cout << i << " ";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}