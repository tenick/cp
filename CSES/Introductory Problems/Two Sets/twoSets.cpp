#include <cstdio>
#include <cstdlib>
#include <vector>

typedef long long ll;

int main() {
    ll n;
    scanf("%Ld", &n);
    ll sum = n * (n + 1) / 2;
    if (sum % 2 == 0) {
        printf("YES\n");
        ll sumHalf = 0;
        ll numIgnore = 0;
        bool theresIgnore = false;
        std::vector<ll> firstSet;
        for (ll i = n; i > 0; i--) {
            if (sumHalf == sum / 2)
                break;
            if (sumHalf + i <= sum / 2) {
                sumHalf += i;
                firstSet.push_back(i);
            }
            else {
                theresIgnore = true;
                numIgnore = sum / 2 - sumHalf;
                sumHalf += numIgnore;
                firstSet.push_back(numIgnore);
            }
        }
        // first set
        printf("%Ld\n", firstSet.size());
        for (ll i = firstSet.size() - 1; i >= 0; i--) {
            printf("%Ld ", firstSet[i]);
        }
        printf("\n");
        // second set
        printf("%Ld\n", abs(n - firstSet.size()));
        if (theresIgnore) {
            for (ll i = 1; i < numIgnore; i++) {
                printf("%Ld ", i);
            }
        }
        for (ll i = numIgnore + 1; i <= n - (firstSet.size() - theresIgnore); i++) {
            printf("%Ld ", i);
        }
        printf("\n");
    }
    else {
        printf("NO\n");
    }
}