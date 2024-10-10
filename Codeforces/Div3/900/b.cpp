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
    arr[0] = 1000;
    arr[1] = 1001;
    for (int i = 2; i < n; i++){
        int prev2 = arr[i-1];
        int newval = prev2+1;

        arr[i] = newval;
    }

    for (int i : arr) cout << i << " ";
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