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
    vector<bool> seen(n, false);
    vector<int> perm;

    for (int curr = 1; curr <= n; curr++){
        if (!seen[curr-1]){
            perm.push_back(curr);
            seen[curr-1] = true;
        }
        int nextVal = curr * 2;
        while (nextVal <= n && !seen[nextVal - 1]){
            perm.push_back(nextVal);
            seen[nextVal - 1] = true;
            nextVal *= 2;
        }
    }

    for (int i : perm) cout << i << " ";
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