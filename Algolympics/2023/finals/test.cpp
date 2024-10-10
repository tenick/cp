#include <iostream>
#include <set>

using namespace std;

void solve(){
    set<int> t1 {1, 2};
    set<int> t2 {2, 1};
    cout << (t1 == t2);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}