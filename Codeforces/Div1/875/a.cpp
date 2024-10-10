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

// use pos = 0, if you want to work with 1st bit of given number
template <typename T> inline bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline void bit_toggle(T& number, int pos) {
    number ^= ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline void bit_set(T& number, int pos) {
    number |= ((T)1 << pos);
}

void solve(){
    int n;
    cin >> n;
    vector<set<pair<int, pair<int, int>>>> vertexByNeighbors(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        vertexByNeighbors[u-1].insert({i, {v-1, u-1}});
        vertexByNeighbors[v-1].insert({i, {u-1, v-1}});
    }
    set<pair<int, pair<int, int>>> nextToRead;
    for (auto neighbor : vertexByNeighbors[0]) {
        nextToRead.insert(neighbor);
    }
    vertexByNeighbors[0].clear();

    int ans = 1;
    while (true) {
        auto nextLowestIndexRead = pair<int,pair<int, int>>{n, {0, 0}};
        while (!nextToRead.empty()) {
            auto currRead = *nextToRead.begin();
            int inputIndex = currRead.first;
            int neighborVertex = currRead.second.first;
            int origVertex = currRead.second.second;

            auto nextIter = vertexByNeighbors[neighborVertex].lower_bound({inputIndex, {0, 0}});
            if (!vertexByNeighbors[neighborVertex].empty()) {
                if ((*vertexByNeighbors[neighborVertex].begin()).first < nextLowestIndexRead.first && (*vertexByNeighbors[neighborVertex].begin()).first != inputIndex)
                    nextLowestIndexRead = *vertexByNeighbors[neighborVertex].begin();
            }
            
            vector<pair<int, pair<int, int>>> toRemove;
            while (nextIter != vertexByNeighbors[neighborVertex].end()) {
                auto nextRead = *nextIter;
                
                nextToRead.insert(nextRead);
                toRemove.push_back(nextRead);
                nextIter++;
            }
            
            for (auto val : toRemove)
                vertexByNeighbors[neighborVertex].erase(val);
            
            nextToRead.erase(currRead);
        }
        if (nextLowestIndexRead.first == n)
            break;
        nextToRead.insert(nextLowestIndexRead);
        ans++;
    }
    cout << ans << '\n';
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