#include <bits/stdc++.h>
using namespace std;
char buf[1111111];
struct state {
    int i = -1, j = -1, d = -1;

    bool operator==(const state& o) const {
        return i == o.i && j == o.j && d == o.d;
    }
    bool operator!=(const state& o) const {
        return !(*this == o);
    }
};

// +1 is left
map<char,int> mp = {{'R', +1}, {'B', -1}, {'S', 0}, {'W', 0}};
vector<pair<int,int>> ds = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};

int r, c;
vector<vector<int>> grid;
inline bool empty(const state& s) {
    return s.i == -1;
}
inline bool in_bounds(const state& s) {
    return 1 <= s.i && s.i <= r && 1 <= s.j && s.j <= c;
}
inline state sunod(const state& s) {
    int di, dj;
    tie(di, dj) = ds[s.d];
    int i = s.i + di, j = s.j + dj;
    return {i, j, s.d + grid[i][j] & 3};
}

void solve() {
    scanf("%d%d", &r, &c);
    grid = vector<vector<int>>(r + 2, vector<int>(c + 2, int('W')));
    int si = -1, sj;
    for (int i = 1; i <= r; i++) {
        scanf("%s", buf);
        for (int j = 1; j <= c; j++) {
            if ((grid[i][j] = buf[j - 1]) == 'S') si = i, sj = j;
        }
    }
    for (int i = 0; i < r + 2; i++) {
        for (int j = 0; j < c + 2; j++) {
            grid[i][j] = mp[grid[i][j]];
        }
    }

    // compute checkpoints
    vector<vector<vector<state>>> checkpoint(r+2, vector<vector<state>>(c+2, vector<state>(ds.size())));

    // from edge cells
    vector<vector<vector<bool>>> is_start(r+2, vector<vector<bool>>(c+2, vector<bool>(ds.size(), true)));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) for (int d = 0; d < ds.size(); d++) {
        state bago = sunod({i, j, d});
        is_start[bago.i][bago.j][bago.d] = false;
    }

    vector<vector<int>> dprev(r+2, vector<int>(c+2, -1));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) for (int d = 0; d < ds.size(); d++) {
        if (!is_start[i][j][d]) continue;
        state start = {i, j, d};
        vector<state> path = {start};
        for (state curr = start; in_bounds(curr); path.push_back(curr = sunod(curr)));
        state last = path.back(); path.pop_back();
        for (const state& st : path) {
            if (dprev[st.i][st.j] != -1) checkpoint[st.i][st.j][dprev[st.i][st.j]] = st;
            dprev[st.i][st.j] = st.d;
        }

        assert(!in_bounds(last));
        for (const state& st : path) {
            if (dprev[st.i][st.j] != -1) {
                checkpoint[st.i][st.j][dprev[st.i][st.j]] = last;
                dprev[st.i][st.j] = -1;
            }
        }
    }

    // in cycles
    vector<vector<vector<int>>> dcycles(r+2, vector<vector<int>>(c+2));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) for (int d = 0; d < ds.size(); d++) {
        if (!empty(checkpoint[i][j][d])) continue;
        state start = {i, j, d};
        vector<state> path = {start};
        for (state bago; (bago = sunod(path.back())) != start; path.push_back(bago));

        for (const state& st : path) dcycles[st.i][st.j].push_back(st.d);
        for (const state& st : path) {
            vector<int>& dcyc = dcycles[st.i][st.j];
            for (int di = 0, dj = dcyc.size() - 1; di < dcyc.size(); dj = di++) {
                checkpoint[st.i][st.j][dcyc[dj]] = {st.i, st.j, dcyc[di]};
            }
            dcyc.clear();
        }
    }

    // compute dests
    vector<vector<bool>> dest(r+2, vector<bool>(c+2));
    vector<vector<int>> visited(r+2, vector<int>(c+2, -1));
    for (int sd = 0; sd < ds.size(); sd++) {
        state start = {si, sj, sd};
        for (state st = start; in_bounds(st);) {
            st = sunod(st);
            int i = st.i, j = st.j, d = st.d;
            dest[i][j] = true;
            if (st == start || !in_bounds(st)) break;
            if (visited[i][j] == sd) continue;
            visited[i][j] = sd;
            if (grid[i][j] == 0) {
                for (int dl : {-1, +1}) {
                    for (int cd = d, it = 0; it < 3; it++) {
                        state chk = checkpoint[i][j][cd + dl & 3];
                        dest[chk.i][chk.j] = true;
                        cd = chk.d;
                        if (!in_bounds(chk)) break;
                        assert(chk.i == i && chk.j == j);
                    }
                }
            }
        }
    }

    // process destinations
    vector<pair<char,int>> res;
    for (int j = 1; j <= c; j++) if (dest.back()[j]) res.emplace_back('B', j);
    for (int i = 1; i <= r; i++) if (dest[i].front()) res.emplace_back('L', i);
    for (int i = 1; i <= r; i++) if (dest[i].back()) res.emplace_back('R', i);
    for (int j = 1; j <= c; j++) if (dest.front()[j]) res.emplace_back('T', j);
    printf("%d\n", int(res.size()));
    for (auto [ch, lc]: res) printf("%c %d\n", ch, lc);
}

int main() {
    int z;
    for (scanf("%d", &z); z--; solve());
}
