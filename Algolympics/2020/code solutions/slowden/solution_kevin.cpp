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

string msg(const string& s, const string& t) {
    vector<vector<vector<bool>>> goods(2, vector<vector<bool>>(C+1));
    for (vector<vector<bool>>& good: goods) for (int c = 0; c <= C; c++) good[c] = vector<bool>(2*(c+2)+1);
    int sl = s.size(), tl = t.size();

    for (int i = 0; i <= sl; i++) {
        vector<vector<bool>> &good = goods[i & 1], &geed = goods[(i & 1) ^ 1];
        for (int c = 0; c <= C; c++) {
            for (int d = 0, j = i - c - 2; d <= 2*(c+2); d++, j++) {
                good[c][d] = 0 <= j && j <= tl && abs(i - j) < c && (!i && !j
                        || i && j && (s[i-1] == t[j-1] ? geed[c][d] : geed[c-1][d-1])
                        || i && geed[c-1][d] || j && good[c-1][d-2]);
            }
        }
    }

    for (int c = 1; c <= C; c++) {
        if (abs(tl - sl) <= c + 2 && goods[sl & 1][c][tl-sl+c+2]) return msgs[c-1];
    }

    return bad_msg;
}

char buf[1111111];
string get_str() { scanf(" %s", buf); return string(buf); }
int main() {
    int z;
    for (scanf("%d", &z); z--; puts(msg(get_str(), get_str()).c_str()));
}
