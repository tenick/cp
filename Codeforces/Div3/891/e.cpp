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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    sort(begin(arr), end(arr));

    map<int, int> valByIndex;
    for (int i = 0; i < n; i++){
        valByIndex[arr[i]] = i;
    }

    vector<int> ps;
    vector<int> ss(n);
    for (int i = 0; i < n; i++){
        int seglen = arr[i] - arr[0] + 1;

        int prev = (i == 0 ? 0 : ps[i-1]);
        ps.push_back(prev + seglen);
    }

    for (int i = n - 1; i >= 0; i--){
        int seglen = arr[n-1] - arr[i] + 1;

        int prev = (i == n - 1 ? 0 : ss[i+1]);
        ss[i] = prev + seglen;
    }

    for (int i = 0; i < n; i++){
        int val = arr[i];
        cout << "val: " << val << " | ";

        int prevpsval = (i == 0 ? 0 : ps[i-1]); 
        int psval = ps[n-1] - prevpsval; 
        int prev = (i == 0 ? 0 : arr[i-1]);
        cout << "prev: " << prev << " | ";
        int psans = psval - (arr[i] - prev) * (n - (i + 1));
        cout << psans << '\n';
    }
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