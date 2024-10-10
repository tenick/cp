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
template <typename T> inline bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline void bit_toggle(T& number, int pos) {
    number ^= ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline void bit_set(T& number, int pos) {
    number |= ((T)1 << pos);
}

bool isRegularBracketSequence(const string& s) {
    stack<char> openInds;
    for (char c : s) {
        if (c == '(') {
            openInds.push(c);
        }
        else {
            if (openInds.empty()) return false;
            openInds.pop();
        }
    }
    return true;
}

bool beautiful(string& s) {
    bool orig = isRegularBracketSequence(s);
    reverse(s.begin(), s.end());
    bool reversed = isRegularBracketSequence(s);
    reverse(s.begin(), s.end());
    return orig || reversed;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int leftcnt = 0;
    int rightcnt = 0;
    for (char c : s) {
        if (c == '(') leftcnt++;
        else rightcnt++;
    }
    if (leftcnt != rightcnt)
        cout << -1 << '\n';
    else {
        if (beautiful(s)) {
            cout << 1 << '\n';
            for (int i = 0; i < n; i++)
                cout << 1 << ' ';
            cout << '\n';
        }
        else {
            vector<int> color1;
            vector<int> closingColor1;
            queue<int> openInds;
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (c == '(') {
                    openInds.push(i);
                }
                else {
                    if (!openInds.empty()) {
                        color1.push_back(openInds.front());
                        openInds.pop();
                        closingColor1.push_back(i);
                    }
                }
            }
            int curr = 0;
            int curr2 = 0;
            cout << 2 << '\n';
            for (int i = 0; i < s.size(); i++) {
                if (curr < color1.size() && color1[curr] == i) {
                    cout << 1 << " ";
                    curr++;
                }
                else if (curr2 < closingColor1.size() && closingColor1[curr2] == i) {
                    cout << 1 << " ";
                    curr2++;
                }
                else cout << 2 << " ";
            }
            cout << '\n';
        }
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