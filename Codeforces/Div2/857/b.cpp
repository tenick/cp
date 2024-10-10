#include <iostream>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int paired = 0;
    int aviaries = 0;
    int pigs = 0;

    for (int i = 0; i < n; i++){
        int plan;
        cin >> plan;
        if (plan == 1){
            pigs++;
            if (pigs > aviaries) aviaries++;
        }
        else {
            int maxAviaries = pigs/2+1;
            if (aviaries > maxAviaries){
                int canPair = pigs/2 - (pigs%2==0); 
                paired += canPair;
                pigs -= canPair*2;
                aviaries -= canPair;
            }
        }
    }
    cout << paired + aviaries << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}