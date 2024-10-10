#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> perm(n, 0);
    perm[n/2] = 1;
    int count = 2;
    for (int i = 0; i < n/2; i++){
        int start = i;
        int end = n-1-i;
        if (start != n/2) perm[start] = count++;
        if (end != n/2) perm[end] = count++;
    }
    for (int i : perm) cout << i << ' ';
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