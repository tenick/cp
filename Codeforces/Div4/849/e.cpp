#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;

        vector<ll> ints(n);
        for (int i = 0; i < n; i++)
            cin >> ints[i];

        ll total = 0;
        bool isOddNeg = false;
        ll minNum = 1e9 + 1;
        for (ll num : ints){
            total += abs(num);
            if (num < 0) isOddNeg = !isOddNeg;
            minNum = min(minNum, abs(num));
        }

        if (isOddNeg) total += minNum * -2;

        cout << total << '\n';
    }
}