#include <bits/stdc++.h>
using namespace std;

const vector<string> msgs = {
    "You're logged in!",
    "You almost got it. You're wrong in just one spot.",
    "You almost got it, but you're wrong in two spots.",
    "You're wrong in three spots.",
};
const string bad_msg = "What you entered is too different from the real password.";
const int C = msgs.size();

string s, t;
vector<vector<map<int,bool>>> memo;
bool lev_le(int i, int j, int d) {
    if (i + j <= d) return true;
    if (abs(i - j) > d) return false;
    if (memo[d][i].count(j)) return memo[d][i][j];
    return memo[d][i][j] = lev_le(i-1, j-1, d - (s[i-1] != t[j-1])) || lev_le(i-1, j, d-1) || lev_le(i, j-1, d-1);
}

string msg(const string& s, const string& t) {
    ::s = s, ::t = t;
    memo.clear(); memo.resize(C, vector<map<int,bool>>(s.size() + 1));
    for (int d = 0; d < C; d++) {
        if (lev_le(s.size(), t.size(), d)) return msgs[d];
    }
    return bad_msg;
}

char buf[1111111];
string get_str() { scanf(" %s", buf); return string(buf); }
int main() {
    int z;
    for (scanf("%d", &z); z--; puts(msg(get_str(), get_str()).c_str()));
}
