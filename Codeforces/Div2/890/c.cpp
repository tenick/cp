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
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = arr[n-1];
    for (int i = 0; i < n-1; i++){
        int usedK = 0;
        ans = max(ans, arr[i]);
        int currVal = arr[i];
        int len = 1;

        for (int j = i+1; j < n; j++){
            if (arr[j] <= currVal){
                if (currVal - arr[j] > k - usedK)
                    break;
                usedK += currVal - arr[j];
                len++;
            }
            else {
                int currK = k - usedK;
                if (currK <= 0)
                    break;

                int toReach = arr[j] - currVal;

                if (currK < toReach * len)
                    break;

                usedK += toReach * len;

                // at this point, arr[i] -> arr[j] == currVal

                currVal = arr[j];
                len++;
            }
        }
        
        cout << "i: " << i << " | len: " << len << " | usedK: " <<  usedK << " | currVal=" << currVal;

        int canAddLen = len - 1;
        int currK = k - usedK;

        cout << " | canAddLen=" << canAddLen << " | currK: " << currK << "\n";

        int l = 0, r = canAddLen;
        while(true){
            int addVal = l * (l + 1) / 2;
            cout << "for l: " << l << " | addVal=" << addVal;
            if (addVal > currK) {
                l--;
                cout << " | stop here at l=" << l << "\n";
                break;
            }
            cout << '\n';
            if (l == r) break;
            l++;
        }
        cout << "the l: " << l << '\n';

        ans = max(ans, currVal + l);
    }
    cout << ans << '\n';
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