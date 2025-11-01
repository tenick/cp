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

// defaults to point-update, iterative bottom-up segment tree
//
// can be a lazy segment tree (decided only during creation, can't be changed after initialization)
//
// lazy segment tree is recursive top-down.
//
// T = type of elements of given array
// U = type of segment tree nodes
//
// sample usages:
//
// // min operation
// segment_tree<int, ll> segtree(
//      arr, 
//      [](ll left_seg_value, ll right_seg_value){return (ll)min(a, b);}, // returns value of tree[node]
//      (ll)LLONG_MAX); // non-lazy seg tree requires only 3 parameters
// 
// // range sum query + update all elements in range to `x`
//  segment_tree<int, ll> lazy_seg_tree(
//      arr, 
//      [](ll left_seg_value, ll right_seg_value){return a+b;}, 
//      (ll)0, 
//      true, 
//      [](ll prev_lazy_value, ll new_lazy_value){ return b; }, // returns resulting lazy_value[node]
//      [](ll prev_tree_value, ll curr_lazy_value, int l, int r) { return (ll)(r-l+1)*val;}); // returns resulting tree[node]
template <typename T, typename U>
class segment_tree {
private:
    int n;
    vector<U> tree;
    vector<U> lazy_value;
    vector<bool> is_lazy_pending;
    vector<int> node_lo;
    vector<int> node_hi;
    const bool IS_LAZY;
    const function<U(U l_seg_value, U r_seg_value)> QUERY_OP;
    const function<U(U prev_lazy_value, U new_lazy_value)> LAZY_VALUE_UPDATE_OP;
    const function<U(U prev_node_value, U lazy_value, int l, int r)> APPLY_LAZY_VALUE_OP;
    const U IDENTITY;

    U init_lazy(const int node, const int l, const int r, const vector<T>& arr) {
        node_lo[node] = l;
        node_hi[node] = r;
        if (l == r) 
            return tree[node] = l >= arr.size() ? IDENTITY : arr[l];

        int nr = (l+r)/2, nl = nr+1;
        return tree[node] = QUERY_OP(init_lazy(node*2, l, nr, arr), init_lazy(node*2+1, nl, r, arr));
    }

    U query_iterative_(int l, int r) {
        l += n;
        r += n;
        U ans = IDENTITY;
        while (l <= r) {
            if (l % 2 == 1) {
                ans = QUERY_OP(ans, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                ans = QUERY_OP(ans, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return ans;
    }

    void update_iterative_(int i, const T new_val) {
        i += n;
        tree[i] = (U)new_val;
        while (i > 1) {
            i /= 2;
            tree[i] = QUERY_OP(tree[i*2], tree[i*2+1]);
        }
    }

    void propagate_(int node) {
        if (!is_lazy_pending[node])
            return;

        int l = node_lo[node], r = node_hi[node];

        tree[node] = APPLY_LAZY_VALUE_OP(tree[node], lazy_value[node], l, r);

        if (l != r) {
            is_lazy_pending[node*2] = true;
            lazy_value[node*2] = LAZY_VALUE_UPDATE_OP(lazy_value[node*2], lazy_value[node]);
            is_lazy_pending[node*2+1] = true;
            lazy_value[node*2+1] = LAZY_VALUE_UPDATE_OP(lazy_value[node*2+1], lazy_value[node]);
        }

        lazy_value[node] = IDENTITY;
        is_lazy_pending[node] = false;
    }
    
    U query_recursive_(const int i, const int j, const int node) {
        int l = node_lo[node], r = node_hi[node];

        // if completely disjoint
        if (j < l || i > r)
            return IDENTITY;

        propagate_(node);

        // if god (l, r) entered into my body (i, j), at most my size
        if (i <= l && j >= r) {
            // cout << "god entered with a value of " << tree[node] << "\n";
            return tree[node];
        }

        return QUERY_OP(query_recursive_(i, j, node*2), query_recursive_(i, j, node*2+1));
    }

    U update_recursive_(const int i, const int j, const int node, const U new_val) {
        int l = node_lo[node], r = node_hi[node];

        // if completely disjoint
        if (j < l || i > r)
            return tree[node];

        propagate_(node);

        // if god (l, r) entered into my body (i, j), at most my size
        if (i <= l && j >= r) {
            is_lazy_pending[node] = true;
            lazy_value[node] = new_val;
            propagate_(node);
            return tree[node];
        }

        return tree[node] = QUERY_OP(update_recursive_(i, j, node*2, new_val), update_recursive_(i, j, node*2+1, new_val));
    }
public:
    segment_tree(
        const vector<T>& arr, 
        function<U(U,U)> query_op, 
        const U identity, 
        const bool is_lazy = false, 
        function<U(U prev_val,U new_val)> lazy_value_update_op = [](U a, U b) {return b;}, 
        function<U(U prev_tree_val,U update_val, int l,int r)> apply_lazy_value_op = [](U prev, U a, int b,int c){return a;})
        : QUERY_OP(query_op), 
            IDENTITY(identity), 
            IS_LAZY(is_lazy), 
            LAZY_VALUE_UPDATE_OP(lazy_value_update_op),
            APPLY_LAZY_VALUE_OP(apply_lazy_value_op) {
        n = arr.size();
        if (IS_LAZY) {
            tree.resize(4*n);
            lazy_value.resize(4*n);
            is_lazy_pending.resize(4*n);
            node_lo.resize(4*n);
            node_hi.resize(4*n);
            init_lazy(1, 0, n-1, arr);
        }
        else { // data is structured differently in a top-down implementation
            tree.resize(2*n);
            for (int i = 0; i < n; i++) tree[n + i] = (U)arr[i];
            for (int i = n-1; i >= 1; i--) {
                tree[i] = QUERY_OP(tree[i*2], tree[i*2+1]);
            }
        }
    }

    U range_query(const int i, const int j) {
        if (IS_LAZY)
            return query_recursive_(i, j, 1);
        else 
            return query_iterative_(i, j);
    }

    void point_update(const int i, const T new_val) {
        if (IS_LAZY)
            update_recursive_(i, i, 1, (U)new_val);
        else 
            update_iterative_(i, new_val);
    }

    void range_update(const int i, const int j, const T new_val) {
        if (IS_LAZY)
            update_recursive_(i, j, 1, new_val);
        else throw std::runtime_error("ERROR: non-lazy segment tree can't range update\n");
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
    segment_tree<int, ll> lazy_seg_tree(
        arr, 
        [](ll a, ll b){return min(a,b);}, 
        (ll)LLONG_MAX, 
        true, 
        [](ll a, ll b){ return b; }, // returns resulting lazy_value[node]
        [](ll prev_tree_value, ll curr_lazy_value, int l, int r) { return curr_lazy_value;}); // returns resulting tree[node]
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            lazy_seg_tree.point_update(a-1, b);
        else
            cout << lazy_seg_tree.range_query(a-1, b-1) << '\n';
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

