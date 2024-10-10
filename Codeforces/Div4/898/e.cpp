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

ll waterAtHeight(ll h, map<int, int>& coralmp){
    ll water = 0;
    ll currDist = 0;
    ll prevh = (*coralmp.begin()).first;

    if (prevh >= h) return 0;

    for (auto& kvp : coralmp){
        ll currh = kvp.first;
        
        if (currh >= h){
            ll add = (h - prevh) * currDist;
            water += add;
            prevh = currh;
            break;
        }
        else {
            ll add = (currh - prevh) * currDist;
            water += add;
        }
        
        currDist += kvp.second;
        prevh = currh;
    }

    if (h > prevh){
        ll add = (h - prevh) * currDist;
        water += add;
    }

    return water;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> coral(n);
    for (int& i : coral) cin >> i;

    map<int, int> coralmp;
    for (int c : coral){
        if (coralmp.find(c) == coralmp.end()) coralmp[c] = 0;
        coralmp[c]++;
    }

    // for (int i = 1; i <= 10; i++){c
    //     cout << "water at height: " << i << " is = " << waterAtHeight(i, coralmp) << '\n';
    // }
    // return;

    ll l=1,r=1e10;
    while(l < r){
        ll mid = (l + r) / 2; // our h
        //cout << "l: " << l << " | r: " << r << " | mid: " << mid << '\n';

        ll water = waterAtHeight(mid, coralmp);
        
        if (water >= x){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (waterAtHeight(r, coralmp) > x) r--;
    cout << r << '\n';
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