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
    int n;
    cin >> n;
    vector<int> game(n);
    for (int& i : game) cin >> i;
    map<int, int> freq;
    for (int i : game){
        if (freq.find(i) == freq.end()) freq[i] = 0;
        freq[i]++;
    }
    int atLeast = 0;
    int most = 0;
    vector<int> dp(n);
    for (auto& kvp : freq){
        if (kvp.first != atLeast) break;
        else if (kvp.second <= atLeast)
            break;
        most = min(most, kvp.second - atLeast - 1);
        atLeast++;
    }


    vector<pair<int, int>> byCnt;
    for (auto& kvp : freq) {
        byCnt.push_back({kvp.second, kvp.first});
    }
    sort(byCnt.begin(), byCnt.end());
    int ind = 0;
    set<int> ext;
    while (ind < n && most > 0){
        if (byCnt[ind].second < atLeast) continue;
        if (byCnt[ind].first <= byCnt[ind].second) break;
        ext.insert(byCnt[ind].second);
        most--;
        ind++;
    }
    bool found = false;
    for (int i : ext){
        if (i == atLeast){
            atLeast++;
            found = true;
        }
        else break;
    }
    if (found) atLeast++;
    cout << atLeast << '\n';
    
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