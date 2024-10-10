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

typedef long long ll;
typedef unsigned long long ull;

const int N = 1000 + 5;
int n = 0, m = 0, k = 0, x = 0, y = 0, a[N] = {}, b[N] = {};

inline void solve(){
	scanf("%d %d %d", &n, &m, &k); k --;
	for(int i = 0 ; i < n ; i ++) scanf("%d", &a[i]);
	for(int i = 0 ; i < m ; i ++) scanf("%d", &b[i]);
	x = y = 0;
	for(int i = 1 ; i < n ; i ++) if(a[i] < a[x]) x = i;
	for(int i = 1 ; i < m ; i ++) if(b[i] > b[y]) y = i;
	if(b[y] > a[x]) swap(a[x], b[y]);
	if(k & 1){
		x = 0, y = 0;
		for(int i = 1 ; i < n ; i ++) if(a[i] > a[x]) x = i;
		for(int i = 1 ; i < m ; i ++) if(b[i] < b[y]) y = i;
		swap(a[x], b[y]);
	}
	long long ans = 0;
	for(int i = 0 ; i < n ; i ++) ans += a[i];
	printf("%lld\n", ans);
	
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}