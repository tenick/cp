#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<ll> parts(n);
    for (ll& i : parts) cin >> i;
    
    int maxpart = *max_element(begin(parts), end(parts));
    if (maxpart <= 0){
        cout << maxpart << '\n';
        return;
    }

    vector<ll> evenparts;
    for (int i = 0; i < parts.size(); i += 2)
        evenparts.push_back(parts[i]);
    vector<ll> oddparts;
    for (int i = 1; i < parts.size(); i += 2)
        oddparts.push_back(parts[i]);
    sort(evenparts.rbegin(), evenparts.rend());
    sort(oddparts.rbegin(), oddparts.rend());
    ll total1 = 0;
    for (int i = 0; i < evenparts.size(); i++){
        if (evenparts[i] < 0) break;
        total1 += evenparts[i];
    }
    ll total2 = 0;
    for (int i = 0; i < oddparts.size(); i++){
        if (oddparts[i] < 0) break;
        total2 += oddparts[i];
    }
    cout << max(total1, total2) << '\n';
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