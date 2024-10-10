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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    set<char> seen;
    string sample;
    for (int i = 0; i < m; i++){
        seen.insert(s[i]);
        if (seen.size() == k){
            seen.clear();
            sample.push_back(s[i]);
        }

        if (sample.size() == n)
            break;
    }
    if (sample.size() != n){
        // find missing char
        char missing;
        for (int i = 0; i < k; i++){
            missing = 'a'+i;
            if (seen.find(missing) == seen.end()) break;
        }
        while (sample.size() != n) sample.push_back(missing);
        cout << "NO\n" << sample << "\n";
    }
    else {
        cout << "YES\n";
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