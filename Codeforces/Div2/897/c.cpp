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

    vector<int> chain;
    for (int i = 0; i < n; i++){
        if (arr[i] != i) break;
        chain.push_back(i);
    }
    if (chain.size() == 0){
        cout << 0 << '\n';
        cout.flush();

        int resp;
        cin >> resp;

        if (resp < 0) return;
    }
    else {
        int ans = chain.size();
        while (true){
            cout << ans << '\n';
            cout.flush();

            int resp;
            cin >> resp;

            if (resp < 0) break;

            ans = resp;
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}