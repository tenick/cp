#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> studs(n);
    for (int i = 0; i < n; i++) cin >> studs[i];

    sort(studs.begin(), studs.end());

    int count = 0;
    for (int i = 0; i < n; i++){
        if (studs[i] <= i){
            count++;
        }
        else break;
    }
    cout << count << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    while (t--){
        solve();
    }
}