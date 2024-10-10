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
    ll n, m, k, h;
    cin >> n >> m >> k >> h;
    //cout << "here1\n";
    vector<ll> peeps(n);
    for (ll& i : peeps) cin >> i;
    //cout << "here2\n";

    ll count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (i == j) continue;

            for (int l = 0; l < n; l++){
                if (peeps[l] == -1) continue;

                ll vladh = h + i * k;
                ll peeph = peeps[l] + j * k;
                //cout << i << ", " << j << " | " << vladh << ", " << peeph << '\n';
                if (vladh == peeph){
                    count++;
                    peeps[l] = -1;
                }
            }
        }
    }

    cout << count << '\n';

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