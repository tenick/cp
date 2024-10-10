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
    int curr = 0;
    int maxans = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if (a <= 10 && b > maxans){
            maxans = b;
            curr = i+1;
        }
    }
    cout << curr << '\n';
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