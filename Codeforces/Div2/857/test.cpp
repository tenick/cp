#include <iostream>
#include <vector>

using namespace std;

void printv(vector<vector<int>>& vec){
    for (auto& v : vec){
        for (int i : v){
            cout << i << " ";
        }
        cout << '\n';
    }
}

int main(){
    int n, m;
    cout << "enter n m: ";
    cin >> n >> m;
    vector<vector<int>> blanket(n, vector<int>(m));
    
    for (int i = 0; i < n/2 + (n % 2 == 1); i++){
        for (int j = 0; j < m/2 + (m % 2 == 1); j++){
            blanket[i*2][j*2] = 0;
            if (i != n-1) blanket[i*2+1][j*2] = 2;
            if (j != m-1) blanket[i*2][j*2+1] = 1;
            if (i != n-1 && j != m-1) blanket[i*2+1][j*2+1] = 3;
        }
    }
    printv(blanket);
    for (int j = 0; j < m; j++){
        int num;
        cout << "xor val: ";
        cin >> num;
        for (int i = 0; i < n; i++){
            blanket[i][j] ^= num;
        }

        printv(blanket);
    }
    for (int i = 0; i < n; i++){
        int num;
        cout << "xor val: ";
        cin >> num;
        for (int j = 0; j < m; j++){
            blanket[i][j] ^= num;
        }

        printv(blanket);
    }
}