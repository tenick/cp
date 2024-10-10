#include <bits/stdc++.h>
using namespace std;
char buf[1111111];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> parent(n);
    for (int i = 0; i < n; i++) scanf("%d", &parent[i]);
    scanf("%s", buf);
    vector<vector<int>> mn(n, vector<int>(2));
    vector<vector<int>> mx(n, vector<int>(2));
    for (int i = 0; i < n; i++) mn[i][1] = mx[i][1] = buf[i] == 'C';
    for (int i = n-1; i > 0; i--) {
        int p = parent[i]-1;
        vector<int> mnc(mn[p].size() + mn[i].size() - 1, n);
        vector<int> mxc(mx[p].size() + mx[i].size() - 1, 0);
        mnc[0] = mxc[0] = 0;
        for (int sp = 1; sp < mn[p].size(); sp++) {
            for (int si = 0; si < mn[i].size(); si++) {
                mnc[sp+si] = min(mnc[sp+si], mn[p][sp]+mn[i][si]);
                mxc[sp+si] = max(mxc[sp+si], mx[p][sp]+mx[i][si]);
            }
        }
        mn[p] = mnc;
        mx[p] = mxc;
    }

    while (q--) {
        int i, c, s;
        scanf("%d%d%d", &i, &c, &s); i--;
        puts(c+s < mn[i].size() && mn[i][c+s] <= c && c <= mx[i][c+s] ? "COMPROMISED" : "NOT COMPROMISED");
    }
}
