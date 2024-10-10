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
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    string s;
    cin >> s;

    int prev = -1;
    int len = 0;
    int prevlen = 0;
    int unsortedAt = 1e9;
    bool reachedBelowUnsorted = true;
    for (char c : s){
        if (c == '+'){
            len++;
        }
        else if (c == '-'){
            len--;

            if (len < unsortedAt)
                reachedBelowUnsorted = true;
        }
        else if (c == '0'){
            if (len <= 1){
                cout << "NO\n";
                return;
            }

            if (prev == 0){
                if (reachedBelowUnsorted)
                    unsortedAt = len;
            }
            else {
                if (reachedBelowUnsorted || len != prevlen)
                    unsortedAt = len;
                else {
                    cout << "NO\n";
                    return;
                }
            }
                
            reachedBelowUnsorted = false;
            prev = 0;
            prevlen = len;
        }
        else if (c == '1'){
            if (prev == 1){
                unsortedAt = len;
            }
            else {
                if (reachedBelowUnsorted)
                    unsortedAt = len;
                else {
                    cout << "NO\n";
                    return;
                }
            }

            reachedBelowUnsorted = false;
            prev = 1;
            prevlen = len;
        }
        
    }
    cout << "YES\n";
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