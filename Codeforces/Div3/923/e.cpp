#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
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
    cin >> n >> k;
    vector<int> a(n, -1);
    int curr = n;
    int curr2 = 1;
    int total = 0;
    int ind = 0;
    int ind2 = 1;
    int i = 0;
    while (total < n){
        while (ind < n){
            a[ind] = curr--;
            ind += k;
            total++;
        }
        while (ind2 < n){
            a[ind2] = curr2++;
            ind2 += k;
            total++;
        }
        ind = i + 2;
        ind2 = i + 1 + 2;
        i += 2;
    }
    for (int i : a) cout << i << ' ';
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