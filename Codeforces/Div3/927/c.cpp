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

vector<int> primeslist;
void get_pfs(int n, map<int, int>& pFactorByCount)
{
    int orig = n;
    
    for (int i : primeslist){
        if (i * i > orig) break;
        if (pFactorByCount.find(i) == pFactorByCount.end())
                pFactorByCount[i] = 0;
        while (n % i == 0)
        {
            pFactorByCount[i]++;
            n = n/i;
        }
    }
   
    if (n > 2){
        if (pFactorByCount.find(n) == pFactorByCount.end())
            pFactorByCount[n] = 0;
        pFactorByCount[n]++;
    }
}

bool checkZero(map<int, int>& mPrimes, map<int, int>& allPrimes){
    for (auto& kvp : mPrimes){
        if (allPrimes.find(kvp.first) == allPrimes.end()){
            return false;
        }
        else {
            if (allPrimes[kvp.first] < kvp.second) return false;
        }
    }
    return true;
}

void outVal(int m, map<int, int>& allPrimes) {
    int val = 1;
    for (auto& kvp : allPrimes){
        for (int j = 0; j < kvp.second; j++){
            val *= kvp.first;
            val %= m;
        } 
    }
    cout << val % m << ' ';
}

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primeslist.push_back(p);
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    map<int, int> allPrimes;
    vector<bool> done(10000, false);
    vector<map<int, int>> primes(10000);
    for (int i : arr){
        get_pfs(i, allPrimes);
        if (!done[i-1]){
            get_pfs(i, primes[i-1]);
            done[i-1] = true;
        }
    }

    if (!done[m-1]){
        get_pfs(m, primes[m-1]);
    }

    bool notzero = false;
    if (checkZero(primes[m-1], allPrimes)){
        cout << 0 << ' ';
    }
    else {
        outVal(m, allPrimes);
        notzero = true;
    }
    
    string s;
    cin >> s;
    int l=0, r=n-1;
    for (char c : s){
        if (l == r) break;

        int toRemove;
        if (c == 'L')
            toRemove = arr[l++];
        else
            toRemove = arr[r--];
        
        for (auto& kvp : primes[toRemove-1]){
            allPrimes[kvp.first] -= kvp.second;
            if (allPrimes[kvp.first] == 0) allPrimes.erase(kvp.first);
        }

        if (!notzero && checkZero(primes[m-1], allPrimes)) cout << 0 << ' ';
        else {
            outVal(m, allPrimes);
            notzero = true;
        }
    }
    cout << '\n';
}

int main(){
    primeslist.clear();
    SieveOfEratosthenes(10000);
    
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}