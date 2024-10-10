#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

int main(){
    int N;
    cin >> N;

    assert(1 <= N && N <= 100000);

    set<ll> heights;

    vector<ll> a;

    for(int i = 0; i<N; i++){
        ll x;
        cin >> x;
        assert(1 <= x && x <= 100000000000LL);
        a.push_back(x);
    }

    vector<pl> c;

    for(int i = 0; i<N; i++){
        ll x;
        cin >> x;
        assert(1 <= x && x <= 100000000000LL);
        assert(heights.count(x) == 0);
        heights.insert(x);
        c.push_back(pl(x, a[i]));
    }

    sort(c.begin(), c.end());
    for(int i = 0; i<N; i++){
        ll out = c[i].second;
        if(i) cout << " ";
        cout << out;
    }

    cout << endl;


    return 0;
}