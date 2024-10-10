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

bool added[16];
int ans(int i, vector<pair<string, string>>& songs){
    if (i == songs.size()) {
        int cnt = 0;
        set<string> genre;
        set<string> writer;
        for (int j = 0; j < 16; j++){
            if (!added[j]) continue;
            if (cnt != 0) {
                if (genre.find(songs[j].first) == genre.end() && 
                    writer.find(songs[j].second) == writer.end()){
                        return songs.size();
                    }
            }
            genre.insert(songs[j].first);
            writer.insert(songs[j].second);
            cnt++;
        }
        return songs.size() - cnt;
    }
    // added
    added[i] = true;
    int ans1 = ans(i+1, songs);
    added[i] = false;
    // removed
    return min(ans1, ans(i+1, songs));

}
void solve(){
    int n;
    cin >> n;
    vector<pair<string, string>> songs;
    for (int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        songs.push_back({s1, s2});
    }
    cout << ans(0, songs) << '\n';
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