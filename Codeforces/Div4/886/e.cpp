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

ull totalc(vector<ull>& sizes, ull w, ull c){
    ull val = 0;
    for (int i = 0; i < sizes.size(); i++){
        val += (sizes[i] + w * 2) * (sizes[i] + w * 2);
        if (val > c) break;
    }
    return val;
}

void solve(){
    ull n, c;
    cin >> n >> c;
    vector<ull> s(n);
    for (ull& i : s) cin >> i;

    ull l=1, r=1e9;
    while (l <= r){
        ull w = (l + r) / 2;
        //cout << l << ", " << r << " | " << w << '\n';

        ull val = totalc(s, w, c);

        if (val == c){
            cout << w << '\n';
            return;
        }

        if (val < c){
            l = w + 1;
        }
        else{
            r = w - 1;
        }
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