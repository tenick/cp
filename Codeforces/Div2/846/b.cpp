#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> lps(n);
        ll sum = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            lps[i] = sum;
        }

        ll maxScore = 1;
        ll currSum = a[n-1];
        for (int i = n-2; i >= 0; i--){
            maxScore = max(maxScore, __gcd(lps[i], currSum));
            currSum += a[i];
        }

        cout << maxScore << '\n';
    }
}
