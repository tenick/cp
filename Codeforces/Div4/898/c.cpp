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
    vector<string> res(10);
    for (string& s : res){
        cin >> s;
    }

    int ans = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (res[i][j] == 'X'){
                int r = i;
                int c = j;
                if (r >= 5) r = (4 - (r - 5));
                if (c >= 5) c = (4 - (c - 5));
                ans += min(r, c) + 1;
            }
        }
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