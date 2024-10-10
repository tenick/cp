#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    int minans = 1e9;
    for (int i = 0; i < n-1; i++){
        if (a[i] > a[i+1]){
            cout << 0 << '\n';
            return;
        }

        minans = min(minans, a[i+1] - a[i]);
    }
    cout << minans / 2 + 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}