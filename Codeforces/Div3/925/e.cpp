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
    auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    for (int i : a){
        int zeroes = 0;
        int digits = 0;
        bool stop = false;
        while (i != 0){
            if (!stop){
                zeroes += i % 10 == 0;
            }
            if (i % 10 != 0) stop = true;
            digits++;
            i /= 10;
        }
        pq.push({zeroes, digits});
    }

    bool anna = true;
    int final = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (anna){
            pq.push({0, curr.second - curr.first});
        }
        else { // sasha's turn
            if (pq.empty()){ // final move
                final += curr.second;
            }
            else {
                auto curr2 = pq.top();
                pq.pop();
                pq.push({min(curr.first, curr2.first), curr.second + curr2.second});
            }
        }
        anna = !anna;
    }

    if (final-1 >= m) cout << "Sasha\n";
    else cout << "Anna\n";
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