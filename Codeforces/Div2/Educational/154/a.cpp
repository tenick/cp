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
    string s;
    cin >> s;


    vector<int> primes{11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int prim = -1;
    for (int prime : primes){
        string primeStr = to_string(prime);
        int curr = 0;
        for (char c : s){
            if (curr == 2) break;
            if (c == primeStr[curr]){
                curr++;
            }
        }
        if (curr == 2){
            prim = prime;
            break;
        }
    }

    cout << prim << "\n";
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