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
    int n, k;
    cin >> n >> k;
    vector<int> l(k);
    vector<int> r(k);
    for (int& i : l) cin >> i;
    for (int& i : r) cin >> i;
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int& i : queries) cin >> i;
    sort(queries.begin(), queries.end());

    int qi = 0;
    for (int i = 0; i < k; i++){
        int lo=l[i]-1, hi=r[i]-1;
        while (qi < q && queries[qi] >= l[i] && queries[qi] <= r[i]){
            int query = queries[qi] - 1;
            int inv = lo + hi - query;
            int from = min(query, inv), to = max(query, inv);
            
        }
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