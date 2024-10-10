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
    int pos;
    cin >> s >> pos;

    int lenSum = s.size();
    char currCh = 'z';
    char ans = 'z';
    for (int i = 0; i < s.size(); i++){
        cout << "at i=" << i << '\n';
        int currLen = s.size() - i - 1;
        if (pos <= lenSum){
            int offset = lenSum - pos;
            cout << "curr lensum = " << lenSum << " offset=" << offset << '\n';
            ans = s[i + currLen - offset];
            cout << "reached here, ans=" << ans << '\n';
            break;
        }

        if (s[i] < s[i+1]) {
            char temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
        cout << " | curr s = " << s << '\n';

        lenSum += currLen;
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