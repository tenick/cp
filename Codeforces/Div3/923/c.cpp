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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> b(m);
    for (int& i : b) cin >> i;

    vector<bool> ansA(k, false);
    vector<bool> ansB(k, false);
    int cnta = 0;
    int cntb = 0;
    for (int i : a){
        if (i <= k && !ansA[i-1]){
            ansA[i-1] = true;
            cnta++;
        }
    }
    for (int i : b){
        if (i <= k && !ansB[i-1]){
            ansB[i-1] = true;
            cntb++;
        }
    }

    bool valid = true;
    for (int i = 0; i < k; i++){
        if (!ansA[i] && !ansB[i]){
            valid = false;
            break;
        }
    }

    if (valid && cnta >= k / 2 && cntb >= k / 2) {
        cout << "YES\n";
    }
    else cout << "NO\n";
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