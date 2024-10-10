#include <iostream>
#include <vector>

using namespace std;

void solve(){
    vector<int> chars(26, -1);
    int n;
    string s;
    cin >> n >> s;

    string ans = "YES\n";
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        if (chars[c - 'a'] == -1){
            chars[c-'a'] = i % 2;
        }
        else {
            if (chars[c-'a'] != i % 2){
                ans = "NO\n";
                break;
            }
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}