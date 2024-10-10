#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> coords;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        coords.push_back({x, y});
    }

    map<int, int> um[4]; 
    // 0: slope = 1; key=b in y=mx+b, 
    // 1: slope = -1; key=b in y=mx+b, 
    // 2: slope = 0; key=b or y in y=mx+b (since y = b)
    // 3: slope = infinity; key=x (cant use y=mx+b, as slope is infinity)

    for (auto& coord : coords){
        //cout << "for coord: " << coord.first << ", " << coord.second << ": ";

        int s0 = coord.second - coord.first;
        if (um[0].find(s0) == um[0].end()) um[0][s0] = 0;
        um[0][s0]++;
        //cout << s0 << ", ";

        int s1 = coord.second + coord.first;
        if (um[1].find(s1) == um[1].end()) um[1][s1] = 0;
        um[1][s1]++;
        //cout << s1 << ", ";
        
        int s2 = coord.second;
        if (um[2].find(s2) == um[2].end()) um[2][s2] = 0;
        um[2][s2]++;
        //cout << s2 << ", ";

        int s3 = coord.first;
        if (um[3].find(s3) == um[3].end()) um[3][s3] = 0;
        um[3][s3]++;
        //cout << s3 << "\n";
    }

    ull total = 0;
    for (int i = 0; i < 4; i++){
        //cout << "i: " << i << " | ";
        for (auto& kvp : um[i]){
            //cout << kvp.first << ", " << kvp.second << " | ";
            total += (ull)kvp.second * (ull)(kvp.second-1);
        }
        //cout << '\n';
    }
    cout << total << '\n';
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