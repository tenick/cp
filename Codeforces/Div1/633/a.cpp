#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
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
    vector<int> arr(n);
    for(int& i : arr) cin >> i;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    multiset<int> ms;
    for (int i : arr) ms.insert(i);

    bool found = false;
    int hi = 0;
    for (int i : arr) {
        ms.erase(ms.find(i));
        if (ms.size() == 0) break;
        int lo2 = *ms.begin();
        if (lo2 < i) {
            found = true;
            hi = max(hi, abs(i - lo2));
        }
    }
    if (found) {
        int cnt = 0;
        int curr = 0;
        int po = 1;
        while (curr < hi) {
            curr += po;
            po = po * 2;
            cnt++;
        }
        cout << cnt << '\n';
    }
    else cout << 0 << '\n';
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
