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
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int ind = 1;
    int curr = a[0];
    set<int> inds;
    for (int i = 0; i < n; i++){
        if (curr != a[i]){
            inds.insert(ind);
            ind = i + 1;
            curr = a[i];
        }
    }
    inds.insert(ind);

    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;

        auto liter = inds.lower_bound(l);
        if (liter != inds.end()){
            if (*liter == l){
                auto nextl = inds.lower_bound(l+1);
                if (nextl != inds.end() && *nextl <= r){
                    cout << *liter << " " << *nextl << '\n';
                    continue;
                }
            }
            else if (*liter <= r){ // just get prev index
                if (*liter != 1){
                    cout << *liter - 1 << " " << *liter << '\n';
                    continue;
                }
            }
        }
        cout << -1 << " " << -1 << '\n';
    }
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