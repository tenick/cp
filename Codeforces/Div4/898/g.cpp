#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    string s;
    cin >> s;

    int acnt = 0;
    int bcnt = 0;
    int bstreak = 0;
    int astreak = 0;
    int ans = 0;
    int minacnt = 1e9;

    int curr = -1;
    for (char c : s){
        if (c == 'A'){
            if (curr != 0){
                if (curr == 1){
                    if (bstreak > 1)
                        bcnt++;
                    bstreak = 0;
                }

                curr = 0;
                acnt++;
            }
            astreak++;
        }
        else {
            if (curr != 1){
                if (curr == 0){
                    ans += astreak;
                    minacnt = min(minacnt, astreak);
                    astreak = 0;
                }

                curr = 1;
                bcnt++;
            }
            bstreak++;
        }
    }

    if (curr == 1 && bstreak > 1) bcnt++;

    if (curr == 0){
        ans += astreak;
        minacnt = min(minacnt, astreak);
        astreak = 0;
    }
    
    cout << (acnt > bcnt ? ans - minacnt : ans) << '\n';
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