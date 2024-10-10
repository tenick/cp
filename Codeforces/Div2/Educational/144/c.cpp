#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--){
        int l, r;
        cin >> l >> r;

        int maxSize = 1;

        int l2 = l;
        while (l2 * 2 <= r){
            maxSize++;
            l2 *= 2;
        }

        int total = (floor(r / pow(2, maxSize - 1)) - l) + 1;
        if (maxSize > 1) total += max(0, (int)(floor(r / (pow(2, maxSize - 2) * 3)) - l) + 1) * (maxSize - 1);

        cout << maxSize << " " << total << '\n';
    }
}