#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> probs(n);
    for (int& i : probs) cin >> i;

    sort(begin(probs), end(probs));

    int prev = probs[0];
    int currseg = 0;
    int maxseg = 1;
    for (int i = 0; i < n; i++){
        //cout << prev << " | " << probs[i] << '\n';
        if (abs(prev - probs[i]) <= k){
            currseg++;
            prev = probs[i];
        }
        else {
            prev = probs[i];
            maxseg = max(maxseg, currseg);
            currseg = 0;
            i--;
        }
    }
    maxseg = max(maxseg, currseg);

    cout << n - maxseg << '\n';
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