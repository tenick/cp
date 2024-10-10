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

void add(int val, vector<int>& vec){
    int toadd = -1;
    vector<int>::iterator toerase = vec.end();

    for (auto it = vec.end()-1; it >= vec.begin(); it--) {
        if (val < *it){
            toadd = val;
            toerase = it;
            break;
        }
    }

    if (toadd == -1) return;

    
    vec.erase(toerase);
    vec.push_back(toadd);
    sort(vec.begin(), vec.end());
}

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arrs(n, vector<int>(2, 1e9));

    for (int i = 0; i < n; i++){
        int m;
        cin >> m;

        for (int j = 0; j < m; j++){
            int val;
            cin >> val;

            add(val, arrs[i]);
        }
    }

    ll total = 0;
    int minleft = 1e9+1;
    int minright = 1e9+1;
    for (int i = 0; i < n; i++){
        minleft = min(minleft, arrs[i][0]);
        minright = min(minright, arrs[i][1]);
        total += arrs[i][1];        
    }

    cout << total + minleft - minright << '\n';
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