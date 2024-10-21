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


unordered_map<int, int> numberByIndex {
    {4, -1}, {8, -1}, {15, -1}, {16, -1}, {23, -1}, {42, -1}
};

void figureOUtOrder(int val, int g1, int g2, int g1Offset, int g2Offset) {
    cout << "? 1 3" << endl;
    int r1;
    cin >> r1;

    if (r1 % val == 0) {
        numberByIndex[val] = 1 + g1Offset;
        numberByIndex[g1/val] = 2 + g1Offset;
        numberByIndex[r1/val] = 1 + g2Offset;
        numberByIndex[g2/(r1/val)] = 2 + g2Offset;
    }
    else {
        numberByIndex[g1/val] = 1 + g1Offset;
        numberByIndex[val] = 2 + g1Offset;
        numberByIndex[r1/(g1/val)] = 1 + g2Offset;
        numberByIndex[g2/(r1/(g1/val))] = 2 + g2Offset;
    }
    cout << "? 5 5" << endl;
    int r2;
    cin >> r2;
    numberByIndex[(int)sqrt(r2)] = 5;
}

bool isValInG1OrG2(int val, int g1, int g2) {
    if (g1 % val != 0 && g2 % val != 0)
        return false;
    int g1offset = 0;
    int g2offset = 2;
    if (g2 % val == 0) {
        swap(g1offset, g2offset);
        swap(g1, g2);
    }
    figureOUtOrder(val, g1, g2, g1offset, g2offset);
    return true;
}
void solve(){
    numberByIndex = {
        {4, -1}, {8, -1}, {15, -1}, {16, -1}, {23, -1}, {42, -1}
    };

    cout << "? 1 2" << endl;
    int a12;
    cin >> a12;

    cout << "? 3 4" << endl;
    int a34;
    cin >> a34;

    if (isValInG1OrG2(15, a12, a34));
    else if (isValInG1OrG2(23, a12, a34));
    else isValInG1OrG2(42, a12, a34);

    vector<int> hiddenArray(6, -1);
    int remaining = -1;
    for (auto& kvp : numberByIndex) {
        if (kvp.second == -1) {
            remaining = kvp.first;
            continue;
        }
        hiddenArray[kvp.second-1] = kvp.first;
    }
    cout << "! ";
    for (int i : hiddenArray) {
        cout << (i == -1 ? remaining : i) << ' ';
    }
    cout << endl;
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