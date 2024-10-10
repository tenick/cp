#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <cstring>

typedef long long ll;
using namespace std;

string a, b;
string diffs;
ll k, maxPairs;
bool chosen[26];

void nCk(int i, int selected){
    if (selected == k){
        ll subTotal = 0;

        int l=-1, r=-1;
        for (int i = 0; i < a.size(); i++){
            if (a[i] == b[i] || chosen[a[i] - 'a']){
                if (l == -1){
                    l = r = i;
                }
                else r++;
            }
            else {
                if (l != -1){
                    ll length = r - l + 1;
                    subTotal += length * (length + 1) / 2; 
                    l = r = -1;
                }
            }
        }
        if (l != -1){
            ll length = r - l + 1;
            subTotal += length * (length + 1) / 2; 
            l = r = -1;
        }

        maxPairs = max(maxPairs, subTotal);
        return;
    }
    if (i == diffs.size()) return;

    for (int j = i; j <= diffs.size() - (k - selected); j++){
        chosen[diffs[j] - 'a'] = true;
        nCk(j+1, selected+1);
        chosen[diffs[j] - 'a'] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n >> k;
        cin >> a >> b;

        if (k == 0){
            // count all substring that match, then sum amount of pairs for each substring (n*(n+1)/2)
            ll maxPair = 0;
            int l=-1, r=-1;
            for (int i = 0; i < n; i++){
                if (a[i] == b[i]){
                    if (l == -1){
                        l = r = i;
                    }
                    else r++;
                }
                else {
                    if (l != -1){
                        ll length = r - l + 1;
                        maxPair += length * (length + 1) / 2; 
                        l = r = -1;
                    }
                }
            }
            if (l != -1){
                ll length = r - l + 1;
                maxPair += length * (length + 1) / 2; 
                l = r = -1;
            }
            cout << maxPair << '\n';
            continue;
        }

        set<char> diffsSet;
        for (int i = 0; i < n; i++){
            diffsSet.insert(a[i]);
        }
        diffs.clear();
        for (char c : diffsSet){
            diffs.push_back(c);
        }

        if (diffs.size() == 0 || k >= diffs.size()){
            // string a and b are (and will be after applying k operations) exactly the same
            cout <<  n*(n+1)/2 << '\n';
            continue;
        }

        memset(chosen, 0, sizeof(chosen));
        maxPairs = 0;
        nCk(0, 0);

        cout << maxPairs << '\n';
    }
}
