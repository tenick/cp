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
    int n;
    cin >> n;
    vector<vector<int>> sets;
    set<int> allUnion;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<int> newvec(k);
        for (int& j : newvec){
            cin >> j;
            allUnion.insert(j);
        }
        sets.push_back(newvec);
    }

    int ans = 0;
    for (int i = 1; i <= 50; i++){
        set<int> currSet;
        for (vector<int>& vset : sets){
            set<int> toInsert;
            bool isInsertable = true;
            for (int j : vset){
                toInsert.insert(j);
                if (j == i){
                    isInsertable = false;
                    break;
                }
            }
            if (isInsertable) currSet.insert(toInsert.begin(), toInsert.end());
        }

        ans = max(ans, (int)(currSet.size() % allUnion.size()));
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