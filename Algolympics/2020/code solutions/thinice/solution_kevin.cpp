#include <bits/stdc++.h>
using namespace std;

struct cell {
    int i, j;
    cell operator+(const cell& o) const { return { i + o.i, j + o.j }; }
    cell operator-(const cell& o) const { return { i - o.i, j - o.j }; }
    bool operator==(const cell& o) const { return i == o.i && j == o.j; }
    bool operator!=(const cell& o) const { return !(*this == o); }
};

string DIRS = "RDLU";
vector<cell> DIJ = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};
map<char, cell> dir;
map<char, char> dir_right, dir_left, dir_reverse;
void init() {
    for (int i = 0; i < DIRS.size(); i++) dir[DIRS[i]] = DIJ[i];
    for (int i = 0, j = DIRS.size() - 1, k = DIRS.size() >> 1; i < DIRS.size(); j = i++, ++k %= DIRS.size()) {
        dir_reverse[dir_right[dir_left[DIRS[i]] = DIRS[j]] = DIRS[i]] = DIRS[k];
    }
}

string rev_all(string res) {
    reverse(res.begin(), res.end());
    for (char& ch: res) ch = dir_reverse[ch];
    return res;
}

void add_some(string& dest, const string& bago) {
    dest.insert(dest.end(), bago.begin(), bago.end());
}

string solve_cyc(int r, int c, int sj, int ej) {
    string res;
    if (sj > ej) {
        add_some(res, rev_all(solve_cyc(r, c, ej, sj)));
    } else {
        add_some(res, string(sj, 'L'));
        for (int it = r >> 1; it --> 1;) {
            res.push_back('U'); add_some(res, string(c - 2, 'R'));
            res.push_back('U'); add_some(res, string(c - 2, 'L'));
        }
        res.push_back('U');
        add_some(res, string(c - 1, 'R'));
        add_some(res, string(r - 1, 'D'));
        add_some(res, string(c - 1 - ej, 'L'));
    }
    return res;
}

string solve(int r, int c, int i, int j) {
    assert(0 <= i && i < r && 0 <= j && j < c);
    if (r % 2 && c % 2 && (i + j) % 2) return "";
    if ((r == 1 || c == 1) && !((i == 0 || i == r - 1) && (j == 0 || j == c - 1))) return "";

    string res;
    #define ROTATE_LR do { for (char ch: solve(c, r, j, r - 1 - i)) res.push_back(dir_left[ch]); } while (0)
    if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1)) {
        if (i) ROTATE_LR; else {
            for (;; j ^= c - 1) {
                add_some(res, string(c - 1, j == 0 ? 'R' : 'L'));
                if (++i < r) res.push_back('D'); else break;
            }
        }
    } else if (i >= 3 || j >= 3 || r - i > 3 || c - j > 3) {
        if (i < 3) ROTATE_LR; else {
            int pad = i - 1 >> 1 << 1;
            cell curr = {i, j};
            for (char ch: solve(r - pad, c, i - pad, j)) {
                cell bago = curr + dir[ch];
                if (curr.i == pad && bago.i == pad) {
                    res.push_back('U');
                    add_some(res, solve_cyc(pad, c, curr.j, bago.j));
                    res.push_back('D');
                    pad = -1;
                } else {
                    res.push_back(ch);
                }
                curr = bago;
            }
        }
    } else if (i >= 1 && j >= 1 && r - i > 1 && c - j > 1) {
        cell curr = {i, j};
        for (char ch: solve(r - 2, c - 2, i - 1, j - 1)) {
            res.push_back(ch);
            curr = curr + dir[ch];
        }
        if (curr.i == 1) { curr.i--; res.push_back('U'); } else
        if (curr.j == 1) { curr.j--; res.push_back('L'); } else
        if (curr.i == r-2) { curr.i++; res.push_back('D'); } else
        if (curr.j == c-2) { curr.j++; res.push_back('R'); } else
            assert(false);
        for (int it = 0; it < 2*(r + c - 2) - 1; it++) {
            if (curr.i > 0 && curr.j == 0) { curr.i--; res.push_back('U'); } else
            if (curr.i == 0 && curr.j < c-1) { curr.j++; res.push_back('R'); } else
            if (curr.i < r-1 && curr.j == c-1) { curr.i++; res.push_back('D'); } else
            if (curr.i == r-1 && curr.j > 0) { curr.j--; res.push_back('L'); } else
                assert(false);
        }
    } else if (i < r-1) ROTATE_LR; else if (r % 2 == 0) {
        add_some(res, solve_cyc(r, c, j, j + (j ? -1 : +1)));
    } else {
        assert(r == 3 && (c == 4 || c == 5) && j != 0 && j != c - 1);
        string small = "LUURDRURDDL", med = "LURRDRUULLLLDD";
        add_some(res, c == 5 ? med : j == 1 ? small : rev_all(small));
    }
    #undef ROTATE_LR
    return res;
}

int main() {
    init();
    int z;
    for (scanf("%d", &z); z--;) {
        int r, c, i, j;
        scanf("%d%d%d%d", &r, &c, &i, &j);
        string s = solve(r, c, i-1, j-1);
        puts(r*c > 1 && s.empty() ? "IMPOSSIBLE": s.c_str());
    }
}
