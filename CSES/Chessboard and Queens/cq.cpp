#include <iostream>
#include <vector>

using namespace std;

bool isAttackedFromAbove(const vector<vector<char>>& chessboard, int row, int col){
    // up
    for (int i = row - 1; i >= 0; i--){
        if (chessboard[i][col] == 'Q')
            return true;
    }

    // left
    int rowL = row - 1;
    int colLeft = col - 1;
    while (rowL >= 0 && colLeft >= 0){
        if (chessboard[rowL][colLeft] == 'Q')
            return true;
        colLeft--;
        rowL--;
    }
    
    // right
    int rowR = row - 1;
    int colRight = col + 1;
    while (rowR >= 0 && colRight < 8){

        if (chessboard[rowR][colRight] == 'Q')
            return true;
        colRight++;
        rowR--;
    }

    return false;
}

int cq(vector<vector<char>>& chessboard, int depth=0){
    if (depth >= 8)
        return 1;

    int count = 0;
    int pos = 0;
    while (pos < 8){
        if (pos > 0 && chessboard[depth][pos - 1] == 'Q')
            chessboard[depth][pos - 1] = '.';

        if (chessboard[depth][pos] != '*' && !isAttackedFromAbove(chessboard, depth, pos)){
            chessboard[depth][pos] = 'Q';
            count += cq(chessboard, depth + 1);
        }

        pos++;
    }

    if (chessboard[depth][pos - 1] == 'Q')
        chessboard[depth][pos - 1] = '.';

    

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> chessboard(8, vector<char>(8, 0));

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> chessboard[i][j];
        }
    }

    int ans = cq(chessboard);
    cout << ans << '\n';
    
}