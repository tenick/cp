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
    for (auto& i : arr) cin >> i;

    int sum = 0;
    for (int i : arr) sum += i;

    int evenCount = 0;
    for (int i : arr){
        if (i % 2 == 1){
            if ((sum - i) % 2 == 1){
                cout << "YES\n";
                return;
            }
        }
        if (i % 2 == 0){
            if ((sum - i) % 2 == 0){
                cout << "YES\n";
                return;
            }
        }
        
    }
    cout <<"NO\n";

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