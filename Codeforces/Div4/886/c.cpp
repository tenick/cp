#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    string ans;
    int i = 0;
    for (int i = 0; i < 8; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++){
            if (s[j] != '.'){
                ans.push_back(s[j]);
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}