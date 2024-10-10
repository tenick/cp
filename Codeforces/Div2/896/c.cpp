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
    int n, m;
    cin >> n >> m;

    if (n == 1 && m > 1){
        cout << 2 << '\n';
    }
    else if (m == 1){
        cout << 0 << '\n';
    }
    else {
        cout << (n < m ? n + 1 : m) << '\n';
    }
    int start = m;
    int end = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = m - end; j < m; j++){
            cout << j << " ";
        }
        for (int k = 0; k < start; k++){
            cout << k << " ";
        }
        if (end < m - 2){
            end++;
            start--;
        }
        cout << '\n';
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