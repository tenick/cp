#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 104857601;
const ll g = 3;
constexpr int sh = 22;
const ll rm = mod >> sh;
ll roots[sh + 1];
ll iroots[sh + 1];
const int N = 1 << sh;

ll ipow(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e & 1) return b * ipow(b, e - 1) % mod;
    return ipow(b * b % mod, e >> 1);
}
ll inv(ll a) { return ipow(a, mod - 2); }

void init() {
    assert(mod == (rm << sh) + 1);
    roots[sh] = ipow(g, rm);
    iroots[sh] = inv(roots[sh]);
    for (int i = sh; i > 0; i--) {
        roots[i - 1] = roots[i] * roots[i] % mod;
        iroots[i - 1] = iroots[i] * iroots[i] % mod;
    }
    assert(roots[0] == 1);
    assert(iroots[0] == 1);
    for (int i = 0; i <= sh; i++) {
        assert((ipow(roots[i], 1 << i) - 1) % mod == 0);
        assert((ipow(iroots[i], 1 << i) - 1) % mod == 0);
        assert((roots[i] * iroots[i] - 1) % mod == 0);
    }
}

inline int lg(ll n) { return __builtin_popcount((n & -n) - 1); }

void _fft(ll *a, ll *t, int n, int k, ll *roots) {
    if (!k) return;
    int j = 0;
    for (int u : {0, 1}) for (int i = u; i < n; i += 2) t[j++] = a[i];
    ll rt = roots[k--], pw = 1;
    n >>= 1;
    _fft(t,   a,   n, k, roots);
    _fft(t+n, a+n, n, k, roots);
    for (int i = 0, j = n; i < n; i++, j++) {
        ll pd = t[j] * pw;
        a[i] = (t[i] + pd) % mod;
        a[j] = (t[i] - pd) % mod;
        pw = pw * rt % mod;
    }
}

ll x[N], t[N];
vector<ll> dft(const vector<ll>& a) {
    int n = a.size(), k = lg(n);
    for (int i = 0; i < n; i++) x[i] = a[i];
    _fft(x, t, n, k, roots);
    return vector<ll>(x, x + n);
}

vector<ll> idft(const vector<ll>& a) {
    int n = a.size(), k = lg(n);
    for (int i = 0; i < n; i++) x[i] = a[i];
    _fft(x, t, n, k, iroots);
    ll sh = ipow(mod + 1 >> 1, k);
    for (int i = 0; i < n; i++) x[i] = x[i] * sh % mod;
    return vector<ll>(x, x + n);
}

struct Poly {
    vector<ll> a;
    int n;
    mutable vector<ll> _dft;
    mutable Poly *_inv = nullptr;
    Poly(const vector<ll>& a, int n = -1): a(a) {
        if (n == -1) n = a.size();
        this->n = n;
        assert(n >= a.size() && n && (n & -n) == n);
    }

    ll operator[](int i) const { return i < a.size() ? a[i] : 0LL; }

    int size() const { return n; }

    Poly operator+(const Poly& o) const {
        assert(size() == o.size());
        vector<ll> x(max(a.size(), o.a.size()));
        for (int i = 0; i < a.size(); i++) x[i] = a[i];
        for (int i = 0; i < o.a.size(); i++) x[i] = (x[i] + o.a[i]) % mod;
        return Poly(x, size());
    }

    Poly operator-(const Poly& o) const {
        assert(size() == o.size());
        vector<ll> x(max(a.size(), o.a.size()));
        for (int i = 0; i < a.size(); i++) x[i] = a[i];
        for (int i = 0; i < o.a.size(); i++) x[i] = (x[i] - o.a[i]) % mod;
        return Poly(x, size());
    }

    Poly operator*(ll c) const {
        c %= mod;
        vector<ll> x(a.size());
        for (int i = 0; i < a.size(); i++) x[i] = a[i] * c % mod;
        return Poly(x, size());
    }
    Poly operator*(const Poly& o) const { return full_mul(o).pref(size()); }
    Poly full_mul(const Poly& o) const {
        assert(size() == o.size());
        vector<ll> r(dft_size());
        for (int i = 0; i < r.size(); i++) r[i] = dft(i) * o.dft(i) % mod;
        return Poly(idft(r));
    }

    Poly operator-() const { return *this * -1; }
    Poly operator/(const Poly& o) const { return *this * *o.inv(); }

    Poly join(const Poly& o) const {
        assert(size() == o.size());
        vector<ll> x(size() * 2);
        for (int i = 0; i < size(); i++) x[i] = (*this)[i];
        for (int i = 0; i < size(); i++) x[i + size()] = o[i];
        return Poly(x);
    }
    
    Poly *inv() const {
        if (!_inv) {
            Poly r({::inv(a[0])});
            while (r.size() < size()) {
                r = r.join(-((pref(r.size()).full_mul(r).suff(r.size()) + sub(r.size(), r.size()) * r) * r));
            }
            assert(r.size() == size());
            _inv = new Poly(r);
        }
        return _inv;
    }

    int dft_size() const { return size() << 1; }
    ll dft(int i) const {
        if (_dft.empty()) {
            vector<ll> a(dft_size());
            for (int i = 0; i < size(); i++) a[i] = (*this)[i];
            _dft = ::dft(a);
        }
        return _dft[i];
    }

    Poly sub(int i, int n) const {
        assert(0 <= i && i <= size());
        assert(0 <= n && n <= size());
        assert(i + n <= size());
        vector<ll> x(n);
        for (int k = 0; k < n; k++) x[k] = (*this)[i + k];
        return Poly(x);
    }
    Poly pref(int n) const { return sub(0, n); }
    Poly suff(int n) const { return sub(size() - n, n); }

    Poly shift(int t) const {
        assert(t >= 0);
        vector<ll> x(size());
        for (int i = t; i < size(); i++) x[i] = (*this)[i - t];
        return Poly(x);
    }
};

ll solve(ll l, ll w) {
    int n = 1;
    while (n < w) n *= 2;

    int s = l + w;
    int t = l - w;
    vector<ll> iv(s, 1LL);
    for (int i = 2; i < s; i++) {
        iv[i] = -(mod/i) * iv[mod%i] % mod;
    }

    vector<ll> ss(w, 1LL);
    vector<ll> tt(w, 1LL);
    vector<ll> SS(w, 1LL);
    vector<ll> TT(w, 1LL);
    tt[0] = 0;
    for (int i = 2; i < w; i++) {
        ss[i] = ss[i - 1] * (2*i - 2) % mod * (2*i - 1) % mod * iv[i - 1] % mod * iv[i] % mod;
        tt[i] = tt[i - 1] * (2*i + t - 2) % mod * (2*i + t - 1) % mod * iv[i - 1] % mod * iv[i + t] % mod;
    }

    for (int i = 1; i < w; i++) {
        SS[i] = SS[i - 1] * (2*i - 1) % mod * (2*i) % mod * iv[i] % mod * iv[i] % mod;
        TT[i] = TT[i - 1] * (2*i + t - 1) % mod * (2*i + t) % mod * iv[i] % mod * iv[i + t] % mod;
    }

    // do the multiplication manually to save fft calls.
    Poly pSS(SS, n);
    Poly pTT(TT, n);
    Poly pss(ss, n);
    Poly ptt(tt, n);

    vector<ll> r(pSS.dft_size());
    for (int i = 0; i < r.size(); i++) r[i] = (pss.dft(i) * pTT.dft(i) - pSS.dft(i) * ptt.dft(i)) % mod;

    Poly num = Poly(idft(r)).pref(n);
    Poly den = pss * pss - (ptt * ptt).shift(t);
    return (num / den)[w - 1];
}

int main() {
    init();
    int l, w;
    scanf("%d%d", &l, &w);
    printf("%lld\n", (solve(l, w) % mod + mod) % mod);
}
