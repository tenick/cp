#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int z;
    for (scanf("%d", &z); z--;) {
        int q;
        ll g, w2 = 0, f = 0, c = 0, w, ff, cc;
        scanf("%d%lld", &q, &g);
        for (int i = 0; i < q; i++) scanf("%lld", &w), w2 += w * w;
        for (int i = 0; i < q; i++) scanf("%lld%lld", &ff, &cc), f += ff, c += cc;
        printf("%.11lf\n", c <= 0 ? 0.0 : f < 0 ? c / (g * sqrt(w2) - f) :
                                                  c * (g * sqrt(w2) + f) / (g * g * w2 - f * f));
    }
}
