#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
    int n, l;
    cin >> n >> l;

    vector<int> peeps(n, -1);
    vector<bool> susList(n);
    for (int i = 0; i < l; i++){
        int id, cdr;
        cin >> id >> cdr;
        if (!susList[id]){
            if (peeps[id] == -1) peeps[id] = cdr;
            else {
                if (peeps[id] == cdr) peeps[id] = -1;
                else 
                    susList[id] = true;
            }
        }
    }
    string susStr = "";
    for (bool b : susList){
        if (b){
            susStr.push_back('1');
        }
        else {
            susStr.push_back('0');
        }
    }
    cout << susStr << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    while (t--){
        solve();
    }
}