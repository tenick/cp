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
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> traps(n);
    for (auto& i : traps){
        int d, s;
        cin >> d >> s;
        i = {d, s};
    }

    sort(traps.begin(), traps.end());

    int currmax = 1e9;
    int loc = 1;
    for (auto& trap : traps){
        int d = trap.first;
        int s = trap.second;

        if (currmax < d) break;

        int maxk = d + (s / 2 - (s % 2 == 0));
        currmax = min(currmax, maxk);
    }
    cout << currmax << '\n';
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