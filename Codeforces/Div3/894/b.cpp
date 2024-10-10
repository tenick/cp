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
    vector<int> b(n);
    for (int& i : b) cin >> i;

    vector<int> a;
    a.push_back(b[0]);
    for (int i = 1; i < n; i++){
        if (b[i] < b[i-1])
            a.push_back(b[i]);
        a.push_back(b[i]);
    }

    cout << a.size() << '\n';
    for (int i : a) cout << i << " ";
    cout << '\n';
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