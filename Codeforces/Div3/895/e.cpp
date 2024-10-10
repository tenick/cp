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
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    string s;
    cin >> s;
    
    int on = 0;
    int off = 0;
    vector<int> px;

    for (int i = 0; i < n; i++){
        char bit = s[i];

        if (bit == '0'){
            off ^= arr[i];
        }
        else {
            on ^= arr[i];
        }

        int prev = px.size() == 0 ? 0 : px[i-1];
        px.push_back(prev ^ arr[i]);
    }

    int q;
    cin >> q;
    while(q--){
        int query;
        cin >> query;
        if (query == 1){
            int l, r;
            cin >> l >> r;

            int val = px[r-1];
            if (l > 1){
                val ^= px[l-2];
            }

            on ^= val;
            off ^= val;
        }
        else {
            int g;
            cin >> g;

            if (g == 0){
                cout << off;
            }
            else {
                cout << on;
            }
            cout << ' ';
        }
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