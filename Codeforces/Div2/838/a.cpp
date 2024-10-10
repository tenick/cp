#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        int sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % 2 == 1){
            int minOps = 1000001;
            for (int i = 0; i < n; i++){
                int currOps = 0;
                int curr = a[i];
                bool prev = curr % 2 == 0;

                while (prev == curr % 2 == 0){
                    currOps++;
                    curr /= 2;
                }

                minOps = min(minOps, currOps);
            }
            cout << minOps << '\n';
        }
        else
            cout << 0 << '\n';
    }
}