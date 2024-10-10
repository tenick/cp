#include <bits/stdc++.h>
using namespace std;
char buf[1111111];
const int N = 10011;
int par[N], szs[N], src[N*(N + 4)], *mns[N], *mxs[N];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &par[i]), szs[i] = 1;
    for (int i = n; --i;) szs[--par[i]] += szs[i];
    for (int i = 0, *sri = src; i < n; szs[i++] = 1) {
        mns[i] = sri; sri += szs[i] + 1;
        mxs[i] = sri; sri += szs[i] + 1;
    }
    scanf("%s", buf);
    for (int i = 0; i < n; i++) mns[i][1] = mxs[i][1] = buf[i] == 'C';
    for (int i = n; --i;) for (int j = szs[par[i]] += szs[i]; j >= 0; j--) {
        int mn = j ? N : 0, mx = j ? -N : 0;
        for (int k = max(1, j - szs[i]); k <= min(j, szs[par[i]] - szs[i]); k++) {
            mn = min(mn, mns[par[i]][k] + mns[i][j-k]);
            mx = max(mx, mxs[par[i]][k] + mxs[i][j-k]);
        }
        mns[par[i]][j] = mn;
        mxs[par[i]][j] = mx;
    }

    while (q--) {
        int i, c, s;
        scanf("%d%d%d", &i, &c, &s); i--;
        puts(c+s <= szs[i] && mns[i][c+s] <= c && c <= mxs[i][c+s] ? "COMPROMISED" : "NOT COMPROMISED");
    }
}
