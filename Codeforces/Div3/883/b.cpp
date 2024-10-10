#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    vector<string> ttt(3);
    cin >> ttt[0];
    cin >> ttt[1];
    cin >> ttt[2];
    char winner = 'n';
    for (int i = 0; i < 3; i++) {
        char p = ttt[i][i];
        if (p == '.') continue;
        bool found = true;
        for (int j = 0; j < 3; j++){
            if (ttt[i][j] != p) {
                found = false;
                break;
            }
        }
        if (found){
            winner = p;
            break;
        }
        found = true;
        for (int j = 0; j < 3; j++){
            if (ttt[j][i] != p) {
                found = false;
                break;
            }
        }
        if (found){
            winner = p;
            break;
        }
    }
    if (winner != 'n'){
        cout << winner << '\n';
        return;
    }
    char p = ttt[1][1];
    bool found = (ttt[0][0] == p && ttt[2][2] == p) || (ttt[0][2] == p && ttt[2][0] == p);
    if (found && p != '.' && p != 'n'){
        cout << p << '\n';
        return;
    }
    cout << "DRAW\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}