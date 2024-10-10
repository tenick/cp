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
    vector<int> martians(n);
    for (int& i : martians) cin >> i;

    int curr = 1;
    int ans = 0;
    for (int i = 0; i < k; i++){
        bool setto1 = true;
        for (int martian : martians){
            setto1 &= ~(martian | curr);
            if (!setto1) break;
        }
        if (setto1) ans += curr;
        curr <<= 1;
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