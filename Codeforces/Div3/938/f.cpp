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
    vector<int> freq(4);
    for (int& i : freq) cin >> i;

    int allOddOrAllEven = (freq[0] % 2 == 0 && freq[1] % 2 == 0 && freq[2] % 2 == 0) || 
                        (freq[0] % 2 == 1 && freq[1] % 2 == 1 && freq[2] % 2 == 1);
    bool decreased = freq[0] % 2 == 1 || freq[1] % 2 == 1 || freq[2] % 2 == 1;
    for (int i = 0; i < 4; i++) {
        if (freq[i] % 2 == 1)
            freq[i]--;
    }

    int wins = allOddOrAllEven + decreased;
    for (int i = 0; i < 3; i++){
        wins += freq[i]/2;
    }

    if (freq[3] != 0) {
        wins += freq[3]/2;
        wins--;
    }
    else wins = max(0, wins-1);

    cout << wins << '\n';
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