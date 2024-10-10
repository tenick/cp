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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    ll ans = 0;
    ll toAdd = 0;

    int firstToAdd = -1;
    for (int i = n-1; i >= 0; i--){
        if (arr[i] >= 0){
            if ((i+1) % 2 == 1) { // at an odd index
                ans += arr[i];
                ans += toAdd;
                toAdd = 0;
                firstToAdd = -1;
            }
            else { // at an even index
                if (firstToAdd == -1)
                    firstToAdd = i;
                toAdd += arr[i];
            }
        }
    }
    if (toAdd > 0){
        ll missed = 0;
        ll maxCanAdd = -1e9;
        for (int i = 0; i <= firstToAdd; i++){
            if (arr[i] >= 0){
                missed += arr[i];
                maxCanAdd = max(maxCanAdd, toAdd - missed);
            }
            else {
                maxCanAdd = max(maxCanAdd, toAdd - missed + ((i+1) % 2 == 1 ? arr[i] : 0));
            }
        }

        ans += maxCanAdd;
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