#include <bits/stdc++.h>

using namespace std;

#define MOD 999983

typedef long long ll;

ll fix_mod(ll x){
    if(x >= 0){
        return x % MOD;
    } else {
        ll y = -x;
        y %= MOD;
        x = MOD - y;
        return x % MOD;
    }
}

vector<int> mul_poly(vector<int> a, vector<int> b){
    // poly[idx] accesses coefficient of x^idx
    vector<int> ans;
    int deg = (a.size()+1) + (b.size()+1);
    ans.assign(deg+1, 0);

    for(int i = 0; i<a.size(); i++){
        for(int j = 0; j<b.size(); j++){
            int deg = i+j;
            int coeff = ((ll) a[i] * (ll) b[j]) % MOD;
            ans[deg] += coeff;
            ans[deg] = fix_mod(ans[deg]);
        }
    }

    // Leading coefficient must be zero
    int first_nonzero_idx = -1;

    for(int idx = ans.size()-1; idx>=0; idx--){
        if(ans[idx]){
            first_nonzero_idx = idx;
            break;
        }
    }

    if(first_nonzero_idx == -1){
        return vector<int>({0});
    }

    vector<int> filtered;
    for(int idx = 0; idx<=first_nonzero_idx; idx++){
        filtered.push_back(ans[idx]);
    }

    return filtered;
}


set<vector<int>> SOLS;

void print_poly(vector<int> & poly){
    cout << poly.size()-1;
    for(int i = poly.size()-1; i>=0; i--){
        cout << " " << poly[i];
    }
    cout << endl;
}

int N, K, L;

void gen_sol(int rem_degree, vector<int> cur_poly){
    // Fit up to exact degree K
    // N is up to 2*10**5, MOD is 999983. Can sweep through N (N < MOD)

    if(SOLS.size() == N){
        return;
    }

    if(!rem_degree){
        SOLS.insert(cur_poly);
        return;
    }

    for(int x = 0; x<MOD; x++){
        vector<int> poly = cur_poly;
        poly = mul_poly(poly, vector<int>({-x, 1}));
        gen_sol(rem_degree-1, poly);
        if(SOLS.size() == N){
            break;
        }
    }

}


int main(){
    int cases;
    cin >> cases;

    for(int e = 0; e<cases; e++){
        SOLS.clear();

        cin >> N >> K >> L;

        vector<int> input;
        set<int> sinput;

        for(int i = 0; i<L; i++){
            int x;
            cin >> x;
            sinput.insert(x);
        }

        for(auto x : sinput){
            input.push_back(x);
        }
        L = input.size();

        vector<int> base_poly({1});
        for(int i = 0; i<L; i++){
            int x = input[i];

            if(x >= 0){
                x %= MOD;
            } else {
                int y = -x;
                y %= MOD;
                x = MOD - y;
                x %= MOD;
            }
            base_poly = mul_poly(base_poly, vector<int>({-x, 1}));
        }

        if(L > K){
            cout << 0 << endl;
        } else if (L == K){
            // Check
            cout << N << endl;
            for(int i = 1; i<=N; i++){
                vector<int> poly = mul_poly(base_poly, vector<int>({i}));
                print_poly(poly);
            }
        } else {
            gen_sol(K-L, base_poly);
            cout << SOLS.size() << endl;

            for(auto sol : SOLS){
                print_poly(sol);
            }
        }




    }




    return 0;
}