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
    int l, r;
    cin >> l >> r;
    
    //cout << "in: " << l << " " << r << '\n';
    if (r < 4){
        cout << "-1\n";
        return;
    }

    //cout << "finished getting primes\n";

    //for (int prime : primes){
    //    cout << prime << " ";
    //}
    //cout << '\n';

    //cout << "in test 1\n";
    int test1 = max(4, l);
    if (test1 % 2 == 0){
        cout << 2 << " " << test1 - 2 << '\n';
        return;
    }
    else {
        //cout << "in test 1 else\n";

        for (int i = 3; i <= ceil(sqrt(test1)); i+= 2){
            int val1 = i;
            int val2 = abs(i - test1);
            //cout << "1. vals: " << val1 << " " << val2 << '\n';

            int high = max(val1, val2);
            int low = min(val1, val2);
            if (low == 0) continue;
            //cout << "2. asdfa: " << high << " " << low << '\n';
            if (high % low == 0 && high != 1 && low != 1){
                cout << high << " " << low << '\n';
                return;
            }
        }

        // for (int prime : primes){
        //     int val1 = prime;
        //     int val2 = abs(prime - test1);
        //     //cout << "1. vals: " << val1 << " " << val2 << '\n';

        //     int high = max(val1, val2);
        //     int low = min(val1, val2);
        //     if (low == 0) continue;
        //     //cout << "2. asdfa: " << high << " " << low << '\n';
        //     if (high % low == 0 && high != 1 && low != 1){
        //         cout << high << " " << low << '\n';
        //         return;
        //     }
        // }
    }

    //cout << "in test 2\n";
    int test2 = l+1;
    if (test2 <= r && test2 % 2 == 0){
        cout << 2 << " " << test2 - 2 << '\n';
        return;
    }

    cout << "-1\n";
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