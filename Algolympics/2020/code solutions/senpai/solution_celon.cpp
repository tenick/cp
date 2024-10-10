#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int solve() {
    int q;
    ll g;
    scanf(" %d %lld", &q, &g);
    // printf(" %d %d\n", q, g);

    vector<ll> W;
    for(int i = 0; i < q; i++) {
        ll temp;
        scanf(" %lld", &temp);

        W.push_back(temp);
    }

    vector<pll> S;
    for(int i = 0; i < q; i++) {
        ll f, c;
        scanf(" %lld %lld", &f, &c);
        // printf("%d %d\n ", f, c);

        S.push_back(make_pair(f, c));
    }

    ll S1 = 0, S0 = 0;
    for(int i = 0; i < q; i++) {
        S1 += S[i].first;
        S0 += S[i].second;
    }

    double K_sum = 0;
    ll W_mag = 0;
    for(int i = 0; i < q; i++) {
        W_mag += W[i]*W[i];
    }
    // printf(" %lld %lld %lld ", S1, S0, W_mag);

    double result = -1;

    if(S0 <= 0)
        result = 0;
    else if(W_mag == 0) {
        result = ((double) S0)/((double) -1*S1);
    } else {
        double W_sol = sqrt((double) W_mag);
        // for(int i = 0; i < q; i++) {
        //     K_sum += g*W[i]*W[i];
        // }
        K_sum = g*W_sol;
        
        // printf("%lld %lf %lld %lf ", S1, K_sum, S0, ((double) K_sum - S1));
        // printf("%lf %lf %lf\n", S0*(g*sqrt(W_mag) + S1), (g*g*W_mag - S1*S1), (g*g*W_mag - S1*S1));

        if(S1 < 0)
            result = S0/(g*W_sol - S1);
        else
            result = (S0*g*sqrt(W_mag) + S0*S1)/(g*g*W_mag - S1*S1);
    }

    // printf(" %llf %lld\n", K_sum, W_mag);
    
    if(result < 0)
        printf("%.6lf\n", 0);
    else
        printf("%.10lf\n", result);
    
    return 0;
}

int main() {
    int z;
    for (scanf("%d", &z); z--; solve());
}
