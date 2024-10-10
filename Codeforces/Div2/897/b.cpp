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
    int n;
    string s;
    cin >> n >> s;
    
    int onesNeeded = 0;
    for (int i = 0; i < n/2; i++){
        if (s[i] != s[n-i-1]){
            onesNeeded++;
        }
    }
    
    int extras = n - onesNeeded*2;
    string ans;
    for (int i = 0; i <= n; i++){
        if (i < onesNeeded){
            ans.push_back('0');
        }
        else if (i == onesNeeded) {
            ans.push_back('1');
        }
        else {
            int remainOnes = i - onesNeeded;
            if (remainOnes <= extras){
                if (extras % 2 == 0) {
                    if (remainOnes % 2 == 0)
                        ans.push_back('1');
                    else ans.push_back('0');
                }
                else {
                    ans.push_back('1');
                }
            }
            else ans.push_back('0');
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