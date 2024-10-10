#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
typedef long long ll;

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

void solve(){
    int n;
    cin >> n;

    vector<ll> A(n);
    vector<ll> B(n);

    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        A[i] = a; B[i] = b;
    }

    ll runningGcd=A[0]*B[0];
    ll runningLcm=1;
    int count = 1;
    for (int i = 0; i < n; i++){
        runningGcd = gcd(runningGcd, A[i] * B[i]);
        runningLcm = lcm(runningLcm, B[i]);
        if (runningGcd % runningLcm != 0){
            count++;
            runningGcd=A[i]*B[i];
            runningLcm=B[i];
        }
    }
    cout << count << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}