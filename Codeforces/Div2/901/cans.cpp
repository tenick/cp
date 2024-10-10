#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int n = 0, m = 0;

inline void solve(){
	scanf("%d %d", &n, &m); n %= m;
	int a = n / __gcd(n, m), b = m / __gcd(n, m);
	if(__builtin_popcount(b) > 1) printf("-1\n");
	else printf("%lld\n", 1ll * __builtin_popcount(a) * m - n);
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}