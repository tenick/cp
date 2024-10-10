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
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> perm(n);
    for (int& i : perm) cin >> i;

    int cnt = 0;
    int win = n+1;
    int lose = n+1;
    for (int x : perm){
        if (x > lose){
            continue;
        }

        if (x > win){
            cnt++;
            lose = min(x, lose);
            continue;
        }
        
        win = min(x, win);
    }
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