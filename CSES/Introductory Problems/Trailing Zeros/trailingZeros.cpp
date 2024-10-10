#include <cstdio>
#include <algorithm>
#include <math.h>

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}

int main() {
    int n, c2=0, c5=0;
    scanf("%d", &n);
    for (int i = 1; i <= intlog(2, n); i++) {
        int ans = (int)(n / pow(2, i));
        c2 += ans;
    }
    for (int i = 1; i <= intlog(5, n); i++) {
        int ans = (int)(n / pow(5, i));
        c5 += ans;
    }
    printf("%d", std::min(c2, c5));
}