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
    map<int, int> numByFreq;
    vector<pair<vector<int>, int>> S;
    vector<pair<pair<set<int>, vector<int>>, int>> Ss;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<int> newvec(k);
        set<int> ss;
        for (int& j : newvec){
            cin >> j;
            ss.insert(j);
        }

        bool found = false;
        for (auto& kvp : Ss){
            set<int>& prevset = kvp.first.first;
            vector<int>& prevVec = kvp.first.second;
            int& subsetsSize = kvp.second;
            if (prevset == ss){
                found = true;
                break;
            }
            if (includes(prevset.begin(), prevset.end(), ss.begin(), ss.end())){ // ss is a subset of prevset
                found = true;
                subsetsSize = max(subsetsSize, (int)ss.size());
                break;
            }
            if (includes(ss.begin(), ss.end(), prevset.begin(), prevset.end())){ // prevset is a subset of ss
                subsetsSize = prevset.size();
                prevset = ss;
                prevVec = newvec;
                found = true;
                break;
            }
        }
        if (found) continue;

        Ss.push_back({{ss, newvec}, 0});
    }
    int subsetTotal = 0;
    for (auto& kvp : Ss){
        S.push_back({kvp.first.second, kvp.second});
        subsetTotal += kvp.second;
    }
    
    for (auto& kvp : S){
        vector<int>& s = kvp.first;
        for (int i : s){
            if (numByFreq.find(i) == numByFreq.end()) numByFreq[i] = 0;
            numByFreq[i]++;
        }
    }

    int allUnion = numByFreq.size();
    int ans = 0;
    for (auto& kvp : S){
        vector<int>& s = kvp.first;
        int zeros = 0;
        for (int i : s){
            numByFreq[i]--;
            if (numByFreq[i] == 0) zeros++;
        }
        
        if (zeros != 0)
            ans = max(ans, allUnion - zeros + kvp.second);

        for (int i : s){
            numByFreq[i]++;
        }
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