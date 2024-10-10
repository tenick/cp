#include <cstdio>
#include <cmath>

typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    ll res = 1;
    for (int i = 0; i < n; i++) {
        res = res * 2 % 1000000007;
    }
    printf("%Ld", res);
}