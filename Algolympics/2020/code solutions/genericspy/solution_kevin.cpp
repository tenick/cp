#include <bits/stdc++.h>
using namespace std;

char buf[1111111];
string get_str() { scanf("%s", buf); return string(buf); }

void enumerate(int n, vector<int>& init, vector<int>& rest, vector<pair<int, int>>& results) {
    if (results.size() >= n || init.empty() || rest.empty()) return;
    int bago = rest.back(); rest.pop_back();
    enumerate(n, init, rest, results);
    int luma = init.back(); init.pop_back();
    if (results.size() < n) results.emplace_back(luma, bago);
    rest.push_back(luma);
    enumerate(n, init, rest, results);
    init.push_back(bago);
}

void solve() {
    int g, n, a;
    scanf("%d%d%d", &g, &n, &a);
    vector<string> names(a);
    map<string, int> namei;
    for (int i = 0; i < a; i++) namei[names[i] = get_str()] = i;
    vector<bool> initset(a);
    vector<int> init, rest;
    for (int i = 0; i < g; i++) init.push_back(namei[get_str()]);
    for (int i : init) initset[i] = true;
    for (int i = 0; i < a; i++) if (!initset[i]) rest.push_back(i);
    vector<pair<int, int>> results;
    enumerate(n - 1, init, rest, results);
    for (auto [luma, bago]: results) printf("%s %s\n", names[luma].c_str(), names[bago].c_str());
}

int main() {
    int z;
    for (scanf("%d", &z); z--; solve(), printf(z ? "\n" : ""));
}
