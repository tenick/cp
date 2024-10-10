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
    vector<vector<int>> ath(n, vector<int>(2)); 
    for (vector<int>& a : ath){
        cin >> a[0] >> a[1];
    }

    int w = ath[0][0];
    int e = ath[0][1];
    bool possible = true;
    for (int i = 1; i < n; i++){
        vector<int>& a = ath[i];
        if (a[0] >= w && a[1] >= e){
            possible = false;
            break;
        }
    }

    cout << (possible ? w : -1) << '\n';
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