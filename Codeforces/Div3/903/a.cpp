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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    bool found = false;
    int cnt = 0;
    for (int i = 0; i < 11; i++){
        if (x.find(s) != string::npos){
            found = true;
            break;
        }
        x += x;
        cnt++;
    }
    if (found){
        cout << cnt << '\n';
    }
    else cout << -1 << '\n';
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