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
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int& i : b) cin >> i;

    for (int i = 0; i < n; i++){
        int val = b[i];
        // forward
        bool inforward = false;
        if (i+k > n){
            int fromstart = n - (i + k);
            if (val <= n || val <= fromstart){
                inforward = true;
            }
        }
        else {
            inforward = val <= i + k;
        }

        bool inbackward = false;
        if ((i+1)-k < 1){
            int fromend = n - ((i+1)-k);
            if (val >= 1 || val >= fromend){
                inbackward = true;
            }
        }
        else {
            inbackward = val >= (i+1)-k;
        }

        if (!inforward || !inbackward){
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