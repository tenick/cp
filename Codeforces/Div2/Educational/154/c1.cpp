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
    int len = 0;
    int sortedAtLen = 1;
    int unsortedAtLen = -1;
    for (char c : s){
        switch (c){
            case '+':
                len++;
                break;
            case '-':
                len--;
                if (len < unsortedAtLen) {
                    unsortedAtLen = -1;
                }
                if (len < sortedAtLen) {
                    sortedAtLen = max(1, len);
                }
                break;
            case '1':
                if (unsortedAtLen >= sortedAtLen){
                    cout << "NO\n";
                    return;
                }
                sortedAtLen = max(1, len);
                unsortedAtLen = -1;
                break;
            case '0':
                if (len <= sortedAtLen){
                    cout << "NO\n";
                    return;
                }
                if (unsortedAtLen == -1)
                    unsortedAtLen = len;
                else unsortedAtLen = min(unsortedAtLen, len);
                break;
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