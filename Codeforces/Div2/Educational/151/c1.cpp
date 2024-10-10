#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long ull;

void solve(){
    string pdb, l, r;
    int m;
    cin >> pdb >> m >> l >> r;
    
    vector<set<int>> digitByPos(10, set<int>());
    for (int i = 0; i < pdb.size(); i++)
        digitByPos[pdb[i]-'0'].insert(i);
    int prevCharPos = pdb.size();
    
    for (int i = m-1; i >= 0; i--){
        int localMaxPos = 0;
        int found = false;
        for (char digit = l[i]; digit <= r[i]; digit++){
            const set<int>& digitSet = digitByPos[digit-'0'];

            if (digitSet.size() == 0)
                continue;

            auto pos = digitSet.lower_bound(prevCharPos);
            if (pos == digitSet.begin()) continue;

            pos--;
            found = true;
            localMaxPos = max(localMaxPos, *pos);
        }
        if (!found) {
            cout << "YES\n";
            return;
        }
        prevCharPos = localMaxPos;
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }

}