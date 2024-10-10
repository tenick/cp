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

char shift(char c) {
    int pos = c - 'a';
    pos++;
    if (pos > 25) pos = 0;
    return 'a' + pos;
}
void modify(int i, int streak, string& s) {
    int start = i - streak + 1;
    for (; start < i; start+=2) {
        while ((start > 0 && s[start-1] == s[start]) || (start < s.size()-1 && s[start+1] == s[start]))
            s[start] = shift(s[start]);
    }
}
void solve(){
    string s;
    cin >> s;
    int streak = 1;
    char prev = shift(s[0]);
    for (int i = 0; i < s.size(); i++) {
        char curr = s[i];
        if (curr == prev) {
            streak++;
        }
        else {
            if (streak > 1) {
                modify(i, streak, s);
                streak = 1;
            }
        }
        prev = curr;
    }
    if (streak > 1)
        modify(s.size(), streak, s);
    cout << s << '\n';
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