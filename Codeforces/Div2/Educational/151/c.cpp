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
    
    bool arr[m][10]{};
    int curr = 0;
    int cnt = 0;
    for (int i = 0; i < pdb.size(); i++){
        int low = l[curr]-'0';
        int high = r[curr]-'0';
        int cdb = pdb[i]-'0';
        if (cdb >= low && cdb <= high && !arr[curr][cdb]){
            arr[curr][cdb] = 1;
            cnt++;
        }

        if (cnt == (high-low+1)){
            curr++;
            if (curr == m){
                cout << "NO\n";
                return;
            }
            cnt = 0;
        }
        
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }

}