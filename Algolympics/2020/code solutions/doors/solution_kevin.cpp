#include <bits/stdc++.h>
using namespace std;

using cell = pair<int,int>;
using state = pair<cell,int>;

char buf[1111111];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};
int solve() {
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    vector<vector<char>> grid(r, vector<char>(c));
    int si = -1, sj, ei = -1, ej;
    for (int i = 0; i < r; i++) {
        scanf("%s", buf);
        for (int j = 0; j < c; j++) {
            if (buf[j] == 'A') {
                assert(si == -1);
                si = i, sj = j;
                buf[j] = '.';
            }
            if (buf[j] == 'B') {
                assert(ei == -1);
                ei = i, ej = j;
                buf[j] = '.';
            }
            assert(buf[j] == '.' || buf[j] == '#' || buf[j] == 'D');
            grid[i][j] = buf[j];
        }
    }
    state start = {{si, sj}, 0};
    cell end_cell = {ei, ej};

    #define in_bounds(i,j) (0 <= (i) && (i) < r && 0 <= (j) && (j) < c)
    #define is_end(st) ((st).first == end_cell)

    #define neighbors(state) do {\
        int ii, jj, dc = state.second;\
        tie(ii, jj) = state.first;\
        for (int d = 0; d < 4; d++) {\
            int ni = ii + di[d], nj = jj + dj[d];\
            if (!in_bounds(ni, nj)) continue;\
            /* move to empty */\
            if (grid[ni][nj] == '.') add_adj(ni, nj, dc, 1);\
            /* move to door */\
            if (grid[ni][nj] == 'D' && (k > 1 || grid[ii][jj] == '.')) add_adj(ni, nj, min(dc + 1, k), 2 + (dc == k));\
        }\
    } while (0)


    vector<vector<state>*> layers(5);
    for (int i = 0; i < 5; i++) layers[i] = new vector<state>;
    layers[0]->push_back(start);
    vector<vector<unordered_set<int>>> vis(r, vector<unordered_set<int>>(c));
    for (int dist = 0, sk = 0; sk < 8; sk++, dist++) {
        for (; !layers[0]->empty(); sk = 0) {
            state i = layers[0]->back(); layers[0]->pop_back();
            if (is_end(i)) return dist;
            if (vis[i.first.first][i.first.second].count(i.second)) continue;
            vis[i.first.first][i.first.second].insert(i.second);
            #define add_adj(ni,nj,ndc,d_) do {\
                state j = {{ni,nj},ndc};\
                int d = (d_);\
                assert(0 <= d && d < layers.size());\
                if (!vis[j.first.first][j.first.second].count(j.second)) layers[d]->push_back(j);\
            } while (0)
            neighbors(i);
            #undef add_adj
        }
        for (int i = 0, j = 1; j < layers.size(); i++, j++) swap(layers[i], layers[j]);
    }
    for (int i = 0; i < 5; i++) delete layers[i];
    #undef neighbors
    #undef in_bounds
    #undef is_end
    return -1;
}

int main() {
    int z;
    for (scanf("%d", &z); z--;) {
        int res = solve();
        if (res == -1) {
            puts("HAHAHUHU");
        } else {
            printf("%d\n", res);
        }
    }
}
