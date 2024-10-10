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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nvec(n);
    for (int& i : nvec) cin >> i;

    vector<int> mvec(m);
    for (int& i : mvec) cin >> i;
    map<int, int> mmap;
    for (int i : mvec) {
        if (mmap.find(i) == mmap.end()) mmap[i] = 0;
        mmap[i]++;
    }
    

    
    int l=0, r=0;
    map<int, int> nsubmap;
    int matching = 0;
    while (r != m - 1) {
        int val = nvec[r];
        if (mmap.find(val) == mmap.end()) {
            r++;
            continue;
        }

        if (nsubmap.find(val) == nsubmap.end()) nsubmap[val] = 0;
        nsubmap[val]++;

        if (nsubmap[val] <= mmap[val]) matching++;
        r++;
    }


    int matchSegs = 0;
    while (r < n) {
        // process new r
        int val = nvec[r];
        if (mmap.find(val) != mmap.end()) {
            if (nsubmap.find(val) == nsubmap.end()) nsubmap[val] = 0;
            nsubmap[val]++;

            if (nsubmap[val] <= mmap[val]) matching++;
        }
        if (matching >= k) matchSegs++;
        r++;

        // remove last l
        int l_val = nvec[l];
        if (mmap.find(l_val) != mmap.end()) {
            nsubmap[l_val]--;
            if (nsubmap[l_val] < mmap[l_val]) matching--;
        }
        l++;
    }

    cout << matchSegs << '\n';
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