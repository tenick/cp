#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 3;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

struct Frac {
    ll n, d;
    Frac(ll n = 0, ll d = 1): n(n), d(d) { normalize(); }

    Frac& normalize() {
        ll g = gcd(n, d);
        n /= g, d /= g;
        if (d < 0) n = -n, d = -d;
        assert(d > 0);
        return *this;
    }

    Frac& operator+=(const Frac& o) {
        ll den = lcm(d, o.d);
        n = n * (den / d) + o.n * (den / o.d);
        d = den;
        return normalize();
    }
    Frac& operator-=(const Frac& o) {
        ll den = lcm(d, o.d);
        n = n * (den / d) - o.n * (den / o.d);
        d = den;
        return normalize();
    }
    Frac& operator*=(const Frac& o) {
        ll gn = gcd(n, o.d);
        ll gd = gcd(d, o.n);
        n = (n / gn) * (o.n / gd);
        d = (d / gd) * (o.d / gn);
        return normalize();
    }
    Frac& operator/=(const Frac& o) {
        ll gn = gcd(n, o.n);
        ll gd = gcd(d, o.d);
        n = (n / gn) * (o.d / gd);
        d = (d / gd) * (o.n / gn);
        return normalize();
    }
    Frac recip() const { return Frac(d, n); }
    Frac operator+(const Frac& o) const { Frac f = *this; return f += o; }
    Frac operator-(const Frac& o) const { Frac f = *this; return f -= o; }
    Frac operator*(const Frac& o) const { Frac f = *this; return f *= o; }
    Frac operator/(const Frac& o) const { Frac f = *this; return f /= o; }
    bool operator<(const Frac& o) const { return (*this - o).sign() < 0; }
    bool operator<=(const Frac& o) const { return (*this - o).sign() <= 0; }
    bool operator>(const Frac& o) const { return (*this - o).sign() > 0; }
    bool operator>=(const Frac& o) const { return (*this - o).sign() >= 0; }
    bool operator==(const Frac& o) const { return n == o.n && d == o.d; }
    bool operator!=(const Frac& o) const { return !(*this == o); }
    int sign() const { return (n > 0) - (n < 0); }
};

struct Pt {
    Frac x, y;
    Pt(const Frac& x = 0, const Frac& y = 0): x(x), y(y) {}

    Pt& operator+=(const Pt& o) { x += o.x; y += o.y; return *this; }
    Pt& operator-=(const Pt& o) { x -= o.x; y -= o.y; return *this; }
    Pt& operator*=(const Frac& s) { x *= s; y *= s; return *this; }

    Pt operator+(const Pt& o) const { Pt p = *this; return p += o; }
    Pt operator-(const Pt& o) const { Pt p = *this; return p -= o; }
    Pt operator*(const Frac& s) const { Pt p = *this; return p *= s; }

    Frac dot(const Pt& o) const { return x * o.x + y * o.y; }
    Frac cross(const Pt& o) const { return x * o.y - y * o.x; }

    bool operator==(const Pt& o) const { return x == o.x && y == o.y; }
    bool operator!=(const Pt& o) const { return !(*this == o); }

    Frac mag2() const { return dot(*this); }

    bool in_line(const Frac& a, const Frac& b, const Frac& c) const { return a * x + b * y == c; }
    bool in_half_plane(const Frac& a, const Frac& b, const Frac& c) const { return a * x + b * y <= c; }
};

vector<Pt> get_points(int n, Frac a, Frac b, Frac c) {
    vector<Pt> res;
    if (a != 0) {
        for (ll i = 0; i < n; i++) {
            Frac y = i, x = (c - b*y) / a;
            res.emplace_back(x, y);
        }
    } else if (b != 0) {
        for (ll i = 0; i < n; i++) {
            Frac x = i, y = (c - a*x) / b;
            res.emplace_back(x, y);
        }
    } else {
        assert(false);
    }
    assert(res.size() == n);
    return res;
}

vector<Pt> intersections(const Pt& p1, const Pt& q1, const Pt& p2, const Pt& q2) {
    Pt v1 = q1 - p1;
    Pt v2 = q2 - p2;
    vector<Pt> res;
    Frac xs = v1.cross(v2);
    if (xs.sign()) {
        Frac t = (p2 - p1).cross(v2) / xs;
        Pt p = p1 + v1*t;
        res.push_back(p);
    }
    return res;
}

struct HPlane {
    Frac a, b, c;
    Pt p1, p2;
    ll rmask;
    HPlane(Frac a, Frac b, Frac c, ll rmask): a(a), b(b), c(c), rmask(rmask) {
        vector<Pt> pts = get_points(2, a, b, c);
        p1 = pts[0];
        p2 = pts[1];
    }
};

vector<HPlane> hplanes;
inline void add_le(ll a, ll b, ll c, ll rmask) { hplanes.emplace_back(a, b, c, rmask); }
inline void add_ge(ll a, ll b, ll c, ll rmask) { add_le(-a, -b, -c, rmask); }

Frac solve(vector<ll> t, ll l, ll u, vector<Frac> probs, vector<vector<Frac>> iprobs) {
    // compute groups
    map<tuple<ll, ll, ll>, Frac> groupm;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        vector<ll> tup = t;
        tup[i] = t[j];
        Frac prod = probs[i] * iprobs[i][j];
        groupm[{tup[0], tup[1], tup[2]}] += probs[i] * iprobs[i][j];
    }

    vector<pair<tuple<ll, ll, ll>, Frac>> groups(groupm.begin(), groupm.end());

    // compute half planes
    hplanes.clear();
    add_ge(1, 0, 0, -1);
    add_ge(0, 1, 0, -1);
    add_le(1, 1, 1, -1);
    for (int idx = 0; idx < groups.size(); idx++) {
        ll a, b, c;
        tie(a, b, c) = groups[idx].first;
        add_le(a-c, b-c, u-c, 1LL << idx);
        add_ge(a-c, b-c, l-c, 1LL << idx);
    }

    Frac ans = 0;
    // find all candidates
    for (int i = 0; i < hplanes.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (const Pt& pt: intersections(hplanes[i].p1, hplanes[i].p2, hplanes[j].p1, hplanes[j].p2)) {
                // process candidate
                ll valid = -1;
                for (const HPlane& hp: hplanes) {
                    if (!pt.in_half_plane(hp.a, hp.b, hp.c)) valid &= ~hp.rmask;
                }

                Frac prob = 0;
                for (int idx = 0; idx < groups.size(); idx++) {
                    if (valid & (1LL << idx)) prob += groups[idx].second;
                }
                ans = max(ans, prob);
            }
        }
    }

    return ans;
}

vector<Frac> get_probs() {
    vector<Frac> res;
    for (int i = 0; i < N; i++) {
        ll n, d;
        scanf("%lld/%lld", &n, &d);
        res.emplace_back(n, d);
    }
    return res;
}

int main() {
    int z;
    for (scanf("%d", &z); z--;) {
        vector<ll> t(N);
        for (int i = 0; i < N; i++) scanf("%lld", &t[i]);
        vector<Frac> probs = get_probs();
        vector<vector<Frac>> iprobs(N);
        for (int i = 0; i < N; i++) iprobs[i] = get_probs();
        ll l, u;
        scanf("%lld%lld", &l, &u);
        Frac res = solve(t, l, u, probs, iprobs);
        printf("%lld/%lld\n", res.n, res.d);
    }
}
