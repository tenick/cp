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
    string s;
    cin >> n >> k >> s;

    int remain = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        char c = s[i];
        if (c == 'B'){
            if (remain != 0) {
                remain--;
                continue;
            }
            remain = k - 1;
            cnt++;
        }
        else {
            if (remain != 0)
                remain--;
        }
    }
    cout << cnt  << '\n';
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