#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> temps(n);
    for (int& t : temps) cin >> t;

    vector<bool> canVisit(n);
    for (int i = 0; i < n; i++){
        if (temps[i] <= q) canVisit[i] = true;
    }
    
    vector<int> consecs;
    bool inSeq = false;
    int start = 0;
    for (int i = 0; i < n; i++){
        if (inSeq){
            if (!canVisit[i]){
                consecs.push_back(i - start);
                inSeq = false;
            }
        }
        else {
            if (canVisit[i]){
                start = i;
                inSeq = true;
            }
        }
    }
    if (inSeq)
        consecs.push_back(n - start);

    long long totalWays = 0;
    for (int secLen : consecs){
        //cout << "seclen: " << secLen << '\n';
        if (secLen < k) continue;
        long long nn = secLen - (k - 1);
        totalWays += nn * (nn + 1) / 2;
    }

    cout << totalWays << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}