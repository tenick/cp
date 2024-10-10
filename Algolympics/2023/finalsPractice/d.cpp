#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solve(){
    int r, c;
    cin >> r >> c;

    set<char> colors;
    for (int i = 0; i < r; i++){
        string s;
        cin >> s;
        for (char c : s)
            colors.insert(c);
    }
    int opsCnt;
    cin >> opsCnt;

    vector<string> ops;
    for (int i = 0; i < opsCnt; i++){
        string op="";
        for (int j = 0; j < 3; j++){
            string opseg;
            cin >> opseg;
            op += opseg;
        }
        ops.push_back(op);
    }

    stack<pair<char, char>> opsStack;
    set<char> done;
    bool possible = true;

    for (string& op : ops){
        char fromColor = op[0];
        char toColor = op[op.size()-1];
        if (fromColor == toColor) continue;

        if (colors.find(fromColor) == colors.end()) continue;
        if (done.find(toColor) != colors.end()){
            possible = false;
            continue;
        }

        done.insert(toColor);
        
        colors.erase(fromColor);
        colors.insert(toColor);

        opsStack.push({fromColor, toColor});
    }

    if (possible){
        cout << "YES\n";
        cout << opsStack.size() << '\n';
        while(!opsStack.empty()){
            auto op = opsStack.top();
            opsStack.pop();
            cout << op.second << " IS " << op.first << '\n';
        }
    }
    else {
        cout << "NO\n";
    }
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    while (t--){
        solve();
    }
}