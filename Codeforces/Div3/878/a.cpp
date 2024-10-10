#include <iostream>
#include <string>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    string finalStr = "";
    while (!s.empty()){
        char curr = s[0];
        int last = s.find(curr, 1);
        s.erase(0, last+1);
        finalStr.push_back(curr);
    }

    cout << finalStr << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}