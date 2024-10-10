#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        int total1s = 0;
        vector<int> monsters(n);
        for (int i = 0; i < n; i++) {
            cin >> monsters[i];
            total1s += monsters[i] == 1;
        }

        int totalMoves = total1s / 2 + (total1s % 2 == 1) + (n - total1s);

        cout << totalMoves << '\n';
    }
}