#include <iomanip>
#include <iostream>
#include <iterator>
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

template <typename T> inline T iceil(T a, T b) {
    return (a + b - 1) / b;
}

#define MOD_ANSWER
#ifdef MOD_ANSWER
constexpr int MOD = 1e9 + 7;
#endif
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2){
            res *= a;
#ifdef MOD_ANSWER
            res %= MOD;
#endif
        } 
        a *= a;
#ifdef MOD_ANSWER
        a %= MOD;
#endif
        b /= 2;
    }
    return res;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> floorByRooms;
    vector<string> n1;
    vector<string> n2;
    for (int i = 0; i < m; i++) {
        int cr; 
        cin >> cr;
        int room = cr % 100;
        string roomStr;
        if (room < 10)
            roomStr.push_back('0');
        roomStr += to_string(room);
        int floor = cr / 100;
        floorByRooms.push_back({floor, roomStr});
    }
    sort(floorByRooms.begin(), floorByRooms.end());
    for (int i = 0; i < n/2; i++) {
        string fr = to_string(floorByRooms[i].first) + floorByRooms[i].second;
        string br = to_string(floorByRooms[m-i-1].first) + floorByRooms[m-i-1].second;
        n1.push_back(fr);
        n1.push_back(br);
        n2.push_back(br);
        n2.push_back(fr);
    }
    if (n % 2 == 1) {
        int i = n/2;
        string fr = to_string(floorByRooms[i].first) + floorByRooms[i].second;
        string br = to_string(floorByRooms[m-i-1].first) + floorByRooms[m-i-1].second;
        n1.push_back(fr);
        n1.push_back(br);
        n2.push_back(br);
        n2.push_back(fr);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cout << (j % 2 == 0 ? n1[i] : n2[i]) << ' ';
        }
        cout << '\n';
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

