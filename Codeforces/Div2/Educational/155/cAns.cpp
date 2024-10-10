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

const int MOD = 998'244'353;

void upd(int &a, int b) {
    a = (a * 1LL * b) % MOD;
}


int t;
string s;

int main() {
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
	    cin >> s;
	    int res = 1;
	    int k = s.size();
	    int n = s.size();
	    for (int l = 0; l < n; ) {
	        int r = l + 1;
	        while(r < n && s[l] == s[r])
	            ++r;
            upd(res, r - l);
            --k;
            l = r;
	    }
	    
	    for (int i = 1; i <= k; ++i)
	        upd(res, i);
        cout << k << ' ' << res << endl;
	}
}