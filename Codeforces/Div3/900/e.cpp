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
    int q;
    cin >> q;
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }
    
    vector<int> pa;
    int prev = arr[0];
    for (int i : arr){
        prev &= i;
        pa.push_back(prev);
    }

    for (int i : pa) cout << i << ' ';
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