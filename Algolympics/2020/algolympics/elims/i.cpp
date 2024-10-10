#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

char board[1000][1000];

pair<char, pair<int, int>> knightMoves[]{
    {'A', {-1, -2}},
    {'B', {-2, -1}},
    {'C', {-2, 1}},
    {'D', {-1, 2}},
    {'E', {1, 2}},
    {'F', {2, 1}},
    {'G', {2, -1}},
    {'H', {1, -2}}
};

unordered_map<char, pair<int, int>> knightMovesMap{
    {'A', {-1, -2}},
    {'B', {-2, -1}},
    {'C', {-2, 1}},
    {'D', {-1, 2}},
    {'E', {1, 2}},
    {'F', {2, 1}},
    {'G', {2, -1}},
    {'H', {1, -2}}
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int r, c;
        cin >> r >> c;

        int startR=-1,startC=-1;
        int endR,endC;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> board[i][j];
                if (board[i][j] == 'K'){
                    startR = i;
                    startC = j;
                }
                if (board[i][j] == 'F'){
                    endR = i;
                    endC = j;
                }
            }
        }

        queue<int> rq;
        queue<int> cq;
        rq.push(startR);
        cq.push(startC);

        string path;
        bool foundPath = false;

        while (!foundPath && !rq.empty()){
            int currR = rq.front();
            int currC = cq.front();
            rq.pop();
            cq.pop();

            for (const auto& move : knightMoves){
                int newR = currR + move.second.first;
                int newC = currC + move.second.second;
                if (newR >= 0 && newR < r && newC >= 0 && newC < c){
                    if (board[newR][newC] == 'O'){
                        rq.push(newR);
                        cq.push(newC);
                        board[newR][newC] = move.first;
                    }
                    else if (newR == endR && newC == endC){
                        foundPath = true;
                        board[newR][newC] = move.first;

                        while (newR != startR || newC != startC){
                            char mov = board[newR][newC];
                            char oppositeMov = 'A' + ((mov - 'A' + 4) % 8);
                            auto& movevec = knightMovesMap[oppositeMov];
                            newR += movevec.first;
                            newC += movevec.second;
                            path.push_back(mov);
                        }
                        
                        break;
                    }
                }
            }
        }
        
        reverse(path.begin(), path.end());
        if (foundPath) cout << "Whinny\n" << path << '\n';
        else cout << "Neigh\n";
    }
}
