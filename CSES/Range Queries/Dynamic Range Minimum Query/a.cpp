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

template <typename T>
constexpr T log_b(T x, T base=2) {
    return std::log(x) / std::log(base);
}

class sparse_table {
private:
    vector<vector<int>> m_st;
    function<int(int,int)> m_f;
public:
    sparse_table(const vector<int>& arr, bool minQ = true) {
        int n = arr.size();
        int LOG = log_b(n)+1;
        m_st.assign(n, vector<int>(LOG));

        m_f = minQ ? [](int a,int b){return min(a,b);}
                 : [](int a,int b){return max(a,b);};

        for (int i = 0; i < n; i++) m_st[i][0] = arr[i];
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n - (1 << (j-1)); i++)
                m_st[i][j] = m_f(m_st[i][j-1], m_st[i+(1 << (j-1))][j-1]);
    }

    int query(int l, int r) {
        int lg = log_b(r-l+1);
        return m_f(m_st[l][lg], m_st[r-(1 << lg)+1][lg]);
    }
};

// bottom-up implementation of segment tree (no range updates for now)
//
// sample usage (for min operation):
//
// `segment_tree<int, ll> segtree(arr, [](ll a, ll b){return (ll)min(a, b);}, (ll)LLONG_MAX);`
template <typename T, typename U>
class segment_tree {
private:
    int n;
    vector<U> tree;
    const function<U(U,U)> OP;
    const U IDENTITY;
public:
    segment_tree(const vector<T>& arr, function<U(U,U)> op, U identity)
        : OP(op), IDENTITY(identity) {
        n = arr.size();
        tree.resize(2*n);
        for (int i = 0; i < n; i++) tree[n + i] = (U)arr[i];
        for (int i = n-1; i >= 1; i--) {
            tree[i] = OP((U)tree[i*2], (U)tree[i*2+1]);
        }
    }

    U query(int l, int r) {
        l += n;
        r += n;
        U ans = IDENTITY;
        while (l <= r) {
            if (l % 2 == 1) {
                ans = OP(ans, (U)tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                ans = OP(ans, (U)tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return ans;
    }

    void update(int i, T new_val) {
        i += n;
        tree[i] = (U)new_val;
        while (i > 1) {
            i /= 2;
            tree[i] = OP((U)tree[i*2], (U)tree[i*2+1]);
        }
    }
};

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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    segment_tree<int, ll> segtree(arr, [](ll a, ll b){return min(a, b);}, (ll)LLONG_MAX);
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            segtree.update(a-1, b);
        else
            cout << segtree.query(a-1, b-1) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}




