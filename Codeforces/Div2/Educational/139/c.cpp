#include <iostream>
#include <vector>
#include <string>
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
        string r1;
        cin >> r1;
        string r2;
        cin >> r2;

        int start = 0;
        bool nextPos = 0;

        for (int i = 0; i < n; i++){
            if (r1[i] != r2[i]){
                start = i + 1;
                nextPos = r2[i] == 'B';
                break;
            }
        }

        string ans = "YES\n";
        for (int i = start; i < n; i++){
            if (r1[i] == 'B' && r1[i] == r2[i])
                nextPos = !nextPos;
            else if ((!nextPos && r1[i] != 'B') || (nextPos && r2[i] != 'B')){
                ans = "NO\n";
                break;
            }
        }
        cout << ans;
    }
}