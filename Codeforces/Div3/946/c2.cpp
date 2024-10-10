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

template <typename T> bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline T bit_toggle(T number, int pos) {
    return number ^ ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline T bit_set(T number, int pos) {
    return number | ((T)1 << pos);
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;


    ll ans = 0;
    map<tuple<int, int, int>, int> triples;
    for (int i = 2; i < n; i++) {
        tuple<int, int, int> triple{nums[i-2],nums[i-1],nums[i]};
        tuple<int, int, int> any1{0,nums[i-1],nums[i]};
        tuple<int, int, int> any2{nums[i-2],0,nums[i]};
        tuple<int, int, int> any3{nums[i-2],nums[i-1],0};
        if (triples.find(any1) != triples.end())
            ans += triples[any1];
        if (triples.find(any2) != triples.end())
            ans += triples[any2];
        if (triples.find(any3) != triples.end())
            ans += triples[any3];
        if (triples.find(triple) != triples.end())
            ans -= triples[triple] * 3;
        if (triples.find(any1) == triples.end())
            triples[any1] = 0;
        if (triples.find(any2) == triples.end())
            triples[any2] = 0;
        if (triples.find(any3) == triples.end())
            triples[any3] = 0;
        triples[any1]++;
        triples[any2]++;
        triples[any3]++;
        if (triples.find(triple) == triples.end())
            triples[triple] = 0;
        triples[triple]++;
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