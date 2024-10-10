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
    vector<int> arr(n);

    for (int& i : arr){
        cin >> i;
    }

    map<int, vector<int>> freq;
    int ind = 0;
    for (int i : arr){
        if (freq.find(i) == freq.end()) freq[i] = {};
        freq[i].push_back(ind);
        ind++;
    }

    int i = n;
    vector<int> ans(n);
    for (auto& kvp : freq){
        while(kvp.second.size() != 0){
            ans[kvp.second.back()] = i;
            kvp.second.pop_back();
            i--;
        }
    }

    for (int a : ans){
        cout << a << " ";
    }
    cout << '\n';

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