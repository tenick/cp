#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve(){
    int m;
    cin >> m;
    vector<vector<int>> data(m);
    for (int i = 0; i < m; i++){
        int n;
        cin >> n;
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            data[i].push_back(a);
        }
    }

    set<int> seen;
    vector<int> winners(m);
    bool possible = true;
    for (int i = m-1; i >= 0; i--){
        int winner = -1;
        for (int j = 0; j < data[i].size(); j++){
            int peep = data[i][j];
            if (seen.find(peep) == seen.end()){
                winner = peep;
            }
            seen.insert(peep);
        }
        if (winner == -1) {
            possible = false;
            break;
        }
        winners[i] = winner;
    }

    if (possible){
        for (int i : winners) cout << i << " ";
        cout << '\n';
    }
    else cout << -1 << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}