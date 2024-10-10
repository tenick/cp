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

char swapBit(char c){
    return c == '1' ? '0' : '1';
}

void solve(){
    string s;
    cin >> s;

    // try for 101010...
    char currc = '1';
    vector<int> indToRemove1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == currc)
            currc = swapBit(s[i]);
        else
            indToRemove1.push_back(i);
    }
    currc = '0';
    vector<int> indToRemove2;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == currc){
            currc = swapBit(s[i]);
        }
        else {
            indToRemove2.push_back(i);
        }
    }

    vector<int>& indToRemove = indToRemove1.size() < indToRemove2.size() ? indToRemove1 : indToRemove2;
    if (indToRemove.size() == 0){
        cout << "0 1\n";
        return;
    }

    ll ans = 1;
    int curr = indToRemove[0]-1;
    int seqLen = 0;
    bool wasZero = curr == -1;
    bool done = false;
    ll mod = 998244353;
    for (int i = 0; i < indToRemove.size(); i++){
        int ind = indToRemove[i];
        if (ind == curr+1){
            curr = ind;
            seqLen++;
        }
        else {
            if (wasZero && !done){
                done = true;
            }
            else seqLen++;
            
            while (seqLen > 0){
                ans *= seqLen;
                seqLen--;
                ans %= mod;
            }
            
            curr = ind-1;
            seqLen = 0;
            i--;
        }
    }
    if (wasZero && !done){
        done = true;
    }
    else seqLen++;
    
    while (seqLen > 0){
        ans *= seqLen;
        seqLen--;
        ans %= mod;
    }

    cout << indToRemove.size() << " " << ans << '\n';
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