#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> piles(n);
    vector<ull> pileSum(n);

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        pileSum[i] = piles[i];
        if (i > 0)
            pileSum[i] += pileSum[i-1];
    }
    
    int l=0,r=n-1;
    while (l < r){
        int mid = (l+r)>>1;
        ull expSum = pileSum[mid] - (l > 0 ? pileSum[l-1]: 0);
        //cout << "expected sum: " << expSum << " | ";
        cout << "? " << mid - l + 1 << " ";
        for (int i = l; i <= mid; i++) cout << (i+1) << " ";
        cout << '\n';
        fflush(stdout);
        
        ull resp;
        cin >> resp;

        if (resp == expSum)
            l = mid+1;
        else r = mid;
    }
    cout << "! " << (l+1) << '\n';

}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}