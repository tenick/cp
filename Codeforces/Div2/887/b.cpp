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

// getting compilation error (size of array too large)
//const int lim = 1e9;
//static int* precompFib = new int[lim];

void solve(){
    int n, k;
    cin >> n >> k;

    // int f2Coef = precompFib[k-1];
    // int f1Coef = precompFib[k-2];

    int f2Coef = 1;
    int f1Coef = 0;

    for (int i = 2; i < k; i++){
        int temp = f2Coef;
        f2Coef += f1Coef;
        f1Coef = temp;

        if (f2Coef > n) {
            cout << 0 << '\n';
            return;
        }
    }

    //cout << f2Coef << ", " << f1Coef << " | ";

    int count = 0;
    for (int f1 = 0; f1 <= n; f1++){
        int x = f1 * f1Coef;
        if (x > n) break;
        if ((n - x) % f2Coef == 0){
            int f2 = (n - x) / f2Coef;
            if (f2 >= f1) {
                count++;
                //cout << "f1: " << f1 << ", f2: " << f2 << '\n';
            }
        }
    }
    cout << count << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    // precompFib[0] = 0;
    // precompFib[1] = 1;
    // for (int i = 2; i < lim; i++)
    //     precompFib[i] = precompFib[i-1] + precompFib[i-2];

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}