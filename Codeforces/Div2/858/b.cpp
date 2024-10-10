#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int zeroes = 0;
    int ones = 0;
    int others = 0;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        bool isZero = num==0;
        bool isOne = num==1;
        zeroes += isZero;
        ones += isOne;
        others += !isZero && !isOne;
    }
    
    if (n - zeroes >= zeroes - 1) cout << 0;
    else if (ones == 0  || others != 0) cout << 1 ;
    else cout << 2;
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}