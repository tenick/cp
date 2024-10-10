#include <iostream>
#include <vector>
#include <set>

typedef unsigned long long ull;

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ull> sockN(n);
    for (int i = 0; i < n; i++) cin >> sockN[i];
    vector<ull> sockM(m);
    for (int i = 0; i < m; i++) cin >> sockM[i];

    set<int> req;
    for (int i = 0; i < m; i++){
        req.insert(sockM[i]);
    }
    
    ull irrelevSocks = 0;
    ull relevSocks = 0;

    for (int i = 0; i < n; i++){
        if (req.find((i+1)) != req.end()){
            relevSocks += sockN[i] * 2;

        }
        irrelevSocks += sockN[i] * 2;
    }
    cout << irrelevSocks - relevSocks + (ull)(req.size() + 1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
