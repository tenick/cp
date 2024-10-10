#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    map<char, vector<int>> cards;
    for (int i = 0; i < 2 * n; i++){
        string s;
        cin >> s;
        if (cards.find(s[1]) == cards.end()) cards[s[1]] = vector<int>();
        cards[s[1]].push_back(s[0]-'0');
    }

    // check first if impossible
    int odds = 0;
    for (auto& kvp : cards) {
        if (kvp.first == trump) continue;
        if (kvp.second.size() % 2 == 1) odds++;
    }
    bool possible = true;
    if (cards[trump].size() < odds){
        possible = false;
    }
    else if ((cards[trump].size() - odds) % 2 == 1){
        possible = false;
    }
    if (!possible){
        cout << "IMPOSSIBLE\n";
        return;
    }

    int used = 0;
    vector<int> trumpRanks = cards[trump];
    sort(trumpRanks.begin(), trumpRanks.end());
    for (auto& kvp : cards) {
        if (kvp.first == trump) continue;

        vector<int> ranks = kvp.second;
        sort(ranks.begin(), ranks.end());

        if (ranks.size() % 2 == 0){
            for (int i = 0; i < ranks.size() / 2; i++){
                cout << ranks[i*2] << kvp.first << " " << ranks[i*2+1] << kvp.first << '\n';
            }
            continue;
        }

        for (int i = 0; i < ranks.size() / 2; i++){
            cout << ranks[i*2] << kvp.first << " " << ranks[i*2+1] << kvp.first << '\n';
        }

        cout << ranks[ranks.size()-1] << kvp.first << " " << trumpRanks[used] << trump << '\n'; 
        used++;
    }

    
    for (int i = used; i < trumpRanks.size(); i+=2){
        cout << trumpRanks[i] << trump << " " << trumpRanks[i+1] << trump << '\n';
    }
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