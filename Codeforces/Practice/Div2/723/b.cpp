#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
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

void sol1() {
    int x;
    cin >> x;
    for (int i = 0; i < 11; i++){
        int a = x - 111 * i;
        if (a >= 0 && a % 11 == 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
void sol2() {
    int x;
    cin >> x;
    if (x % 11 * 110 > x) cout << "NO\n";
    else cout << "YES\n";
}

void solve(){
    sol2();
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