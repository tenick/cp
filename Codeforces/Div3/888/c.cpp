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
    int n, k;
    cin >> n >> k;
    vector<int> colors(n);
    for (int& i : colors) cin >> i;

    int sc = colors[0];
    int ec = colors[n-1];
    vector<int> color;
    vector<int> amt;
    color.push_back(colors[0]);
    amt.push_back(k-1);
    if (n != 1){
        if (colors[n-1] != color[0]){
            color.push_back(colors[n-1]);
            amt.push_back(k-1);
        }
        else amt[0] = max(amt[0] - 1, 0);
    }


    int coli = 0;
    while (coli < amt.size() && amt[coli] == 0){
        coli++;
    }
    for (int i = 1; i < n-1; i++){
        if (coli == amt.size()) break;

        if (colors[i] == color[coli]){
            amt[coli]--;
            if (amt[coli] == 0) coli++;
        }
    }

    for (int am : amt) {
        if (am != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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