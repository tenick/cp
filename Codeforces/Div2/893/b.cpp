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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> sellers(m);
    for (int& i : sellers) cin >> i;

    int prevEat = 1;
    int cnt = 1;
    
    for (int i = 0; i < m; i++){
        int travel = sellers[i] - prevEat;
        int cookies = travel / d;
        if (travel % d != 0) cookies++;
        prevEat = sellers[i];

        cnt += cookies;
    }
    int travel = n - prevEat;
    int cookies = travel / d;
    cnt += cookies;

    cout << cnt << '\n';

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