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

// use pos = 0, if you want to work with 1st bit of given number
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

    vector<int> enter_order(n);
    vector<int> exit_order(n);

    // Input the entry order
    for (int i = 0; i < n; ++i) {
        cin >> enter_order[i];
    }

    // Input the exit order
    for (int i = 0; i < n; ++i) {
        cin >> exit_order[i];
    }

    // Step 1: Create a map to store the position of each car in the entry order
    unordered_map<int, int> enter_pos;
    for (int i = 0; i < n; ++i) {
        enter_pos[enter_order[i]] = i;
    }

    // Step 2: Iterate through the exit order and track overtaking cars
    int max_enter_pos = -1;
    int fined_count = 0;

    for (int i = 0; i < n; ++i) {
        int car = exit_order[i];
        if (enter_pos[car] < max_enter_pos) {
            // If the current car's entry position is less than the max, it overtook some car
            fined_count++;
        } else {
            // Update the maximum entry position encountered
            max_enter_pos = enter_pos[car];
        }
    }

    // Output the result
    cout << fined_count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}