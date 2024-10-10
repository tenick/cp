#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) arr.push_back((i+1) * 2);
    int sum = (n * (n + 1) / 2);
    int negs = sum - k;
    int len = n;
    for (int i = 0; i < n; i++){
        
        if (negs <= 0) break;

        int toCover = min(negs, len);

        arr[i] =   -(toCover  * (((i+1)*4) + (toCover - 1) * 2) / 2 + 1);
        //cout << "at " << i << ": " << arr[i] << " | to cover: " << toCover << " | negs: " << negs << '\n';
        negs -= len;
        len--;
    }

    for (int i : arr) cout << i << " ";
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