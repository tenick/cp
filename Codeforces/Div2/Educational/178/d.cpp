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

const int MAX_PRIME = 5800079;
bool sieve[MAX_PRIME+2];

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    sort(arr.rbegin(), arr.rend());
    int p = 2;
    vector<int> leftover;
    ll coins = 0;
    for (int i = 0; i < n; i++) {
        while (!sieve[p]) p++;
        //cout << "curr prime = " << p  << " val = " << arr[i] << '\n';
        if (arr[i] < p) {
            leftover.push_back(arr[i]);
            continue;
        }
        coins += arr[i] - p;
        p++;
    }
    //cout << "total coins = " << coins << '\n';
    int handled = 0;
    for (int i = 0; i < leftover.size(); i++) {
        while (!sieve[p]) p++;
        //cout << "curr prime in leftovers = " << p << " leftover = " << leftover[i] << '\n';
        if (p - leftover[i] <= coins) {
            handled++;
            coins -= p - leftover[i];
            p++;
            continue;
        }
        break;
    }
    cout << leftover.size() - handled << '\n';
}

void SieveOfEratosthenes()
{
    for (int p = 2; p * p <= MAX_PRIME; p++) {
        if (sieve[p] == true) {
            for (int i = p * p; i <= MAX_PRIME; i += p)
                sieve[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    memset(sieve, 1, sizeof(sieve));
    SieveOfEratosthenes();

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}

