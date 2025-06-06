#include <climits>
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

vector<array<int, 2>> moves {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
map<char, array<int, 2>> dirByMove {
    {'U', moves[0]},
    {'R', moves[1]},
    {'D', moves[2]},
    {'L', moves[3]}
};

void printVisited(const vector<vector<int>>& visited) {
    for (auto& row : visited) {
        for (int i : row)
            cout << i << ' ';
        cout << '\n';
    }
    cout << '\n';
}
bool invalidPos(int r, int c, const vector<vector<int>>& visited) {
    return r < 0 || r >= 7 || c < 0 || c >= 7 || visited[r][c];
}
int rcway(int r, int c, int cnt, vector<vector<int>>& visited, const string& desc) {
    if (invalidPos(r, c, visited))
        return 0;
    if (r == 6 && c == 0) {
        if (cnt == 49)
            return 1;
        else return 0;
    }

    // pruning 1: avoid cutting grid horizontally and vertically
    if (invalidPos(r+1, c, visited) && invalidPos(r-1, c, visited) 
            && !invalidPos(r, c-1, visited) && !invalidPos(r, c+1, visited))
        return 0;
    if (invalidPos(r, c+1, visited) && invalidPos(r, c-1, visited) 
            && !invalidPos(r-1, c, visited) && !invalidPos(r+1, c, visited))
        return 0;

    // pruning 2: avoid diagonally cutting grid
    if (invalidPos(r-1, c+1, visited) 
            && !invalidPos(r, c+1, visited) && !invalidPos(r-1, c, visited))
        return 0;
    if (invalidPos(r-1, c-1, visited) 
            && !invalidPos(r-1, c, visited) && !invalidPos(r, c-1, visited))
        return 0;
    if (invalidPos(r+1, c+1, visited) 
            && !invalidPos(r+1, c, visited) && !invalidPos(r, c+1, visited))
        return 0;
    if (invalidPos(r+1, c-1, visited) 
            && !invalidPos(r+1, c, visited) && !invalidPos(r, c-1, visited))
        return 0;


    visited[r][c] = cnt;
    int total = 0;
    if (desc[cnt-1] == '?') {
        for (auto& move : moves) {
            total += rcway(r+move[0], c+move[1], cnt+1, visited, desc);
        }
    }
    else {
        auto& move = dirByMove[desc[cnt-1]];
        total += rcway(r+move[0], c+move[1], cnt+1, visited, desc);
    }
    visited[r][c] = 0;
    
    return total;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    string desc;
    cin >> desc;
    vector<vector<int>> visited(7, vector<int>(7, 0));
    cout << rcway(0, 0, 1, visited, desc) << '\n';
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

