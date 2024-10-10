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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> health(n);
    for (int& i : health) cin >> i;
    vector<int> pos(n);
    for (int& i : pos) cin >> i;

    int posi = lower_bound(pos.begin(), pos.end(), 0) - pos.begin();
    int negi = posi-1;
    ll boulets = 0;
    int prevpos = 0;
    while (posi < n || negi >= 0){
        int currpospos = 1e9+1;
        int currnegpos = 1e9+1;
        if (posi < n) currpospos = pos[posi];
        if (negi >= 0) currnegpos = abs(pos[negi]);
        
        // i need more boulets!!
        ll newBouletsToAdd = 0;
        int reqBoulets = 0;
        int newPos = 0;
        if (currpospos <= currnegpos){
            newBouletsToAdd = 1ll * (currpospos - prevpos) * k;
            newPos = currpospos;
            reqBoulets += health[posi];
            posi++;
        }
        if (currnegpos <= currpospos){
            newBouletsToAdd = 1ll * (currnegpos - prevpos) * k;
            newPos = currnegpos;
            reqBoulets += health[negi];
            negi--;
        }
        prevpos = newPos;
        boulets += newBouletsToAdd;

        boulets -= reqBoulets;
        if (boulets < 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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