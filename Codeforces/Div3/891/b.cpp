#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    string s;
    cin >> s;

    int lastRound = s.size();
    for (int i = s.size()-1; i >= 0; i--){
        int val = s[i] - '0';
        bool canRnd = val >= 5;

        if (canRnd){
            if (i != 0){
                if (s[i-1]-'0' != 9){
                    s[i-1]++;
                }
            }
            lastRound = i;
        }
    }

    for (int i = lastRound; i < s.size(); i++){
        s[i] = '0';
    }
    if (lastRound == 0) s = '1' + s;

    cout << s << '\n';
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