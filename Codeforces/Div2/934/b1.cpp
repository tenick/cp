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
    vector<int> l(n);
    for (int& i : l) cin >> i;
    vector<int> r(n);
    for (int& i : r) cin >> i;

    map<int, int> freq1;
    for (int i : l) {
        if (freq1.find(i) == freq1.end()) freq1[i]=0;
        freq1[i]++;
    }
    vector<int> e1;
    vector<int> o1;
    for (auto& kvp : freq1){
        if (kvp.second % 2 == 0) e1.push_back(kvp.first);
        else o1.push_back(kvp.first);
    }

    map<int, int> freq2;
    for (int i : r) {
        if (freq2.find(i) == freq2.end()) freq2[i]=0;
        freq2[i]++;
    }
    vector<int> e2;
    vector<int> o2;
    for (auto& kvp : freq2){
        if (kvp.second % 2 == 0) e2.push_back(kvp.first);
        else o2.push_back(kvp.first);
    }
    
    if (e1.size() >= k){
        for (int i = 0; i < k; i++){
            cout << e1[i] << " " << e1[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < k; i++){
            cout << e2[i] << " " << e2[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < 2 * k; i++){
            cout << o1[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < 2 * k; i++){
            cout << o2[i] << ' ';
        }
        cout << '\n';
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