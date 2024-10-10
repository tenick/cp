#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

void solve(){
    string s;
    cin >> s;
    set<char> sc;
    vector<int> cnt(10);
    for (char c : s) {
        sc.insert(c);
        cnt[c-'0']++;
    }
    if (sc.size() == 4) cout << 4;
    else if (sc.size() == 3) cout << 4;
    else if (sc.size() == 2){
        char fc = *sc.begin();
        if (cnt[fc-'0'] == 1 || cnt[fc-'0'] == 3)
            cout << 6;
        else cout << 4;
    }
    else if (sc.size() == 1) cout << -1;
    
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