#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> b(n);
    for (int& i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans1 = 0;
    for (int i = 0; i < n; i++){
        ans1 += a[0] + b[i];
    }
    ll ans2 = 0;
    for (int i = 0; i < n; i++){
        ans2 += b[0] + a[i];
    }
    cout << min(ans1, ans2) << '\n';
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