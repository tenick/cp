#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<int> divisors;
        int lim = floor(sqrt(n));
        int p1 = 2 * pow(10, 9) + 1;
        int p2 = p1;
        int dist = p2;
        for (int i = 1; i <= lim; i++){
            if (n % i == 0){
                int temp1 = n / i;
                int temp2 = n - temp1;
                int temp3 = abs(temp1 - temp2);
                if (temp3 < dist){
                    p1 = temp1;
                    p2 = temp2;
                    dist = temp3;
                }
            }
        }
        
        if (p1 == n) { p2 = n - 1; p1 = 1; }
        cout << p1 << ' ' << p2 << '\n';
    }
}