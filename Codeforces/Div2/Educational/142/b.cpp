#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        vector<int> jokes(4);
        for (int i = 0; i < 4; i++) cin >> jokes[i];
        if (jokes[0] == 0) cout << 1 << '\n';
        else {
            int min23 = min(jokes[1], jokes[2]);
            int max23 = max(jokes[1], jokes[2]);

            

            int maxJokes = 1 + min23 * 2 + min(max23, 2);

            if (max23 - min23  >= 2) maxJokes += (jokes[0] - 1);
            else {
                jokes[0]--;
                if (max23 - min23 == 1) jokes[0]--;

                int min14 = min(jokes[0], jokes[3]);
                int max14 = max(jokes[0], jokes[3]);

                cout << "jokes: " << jokes[0] << "\n";
            }
            cout << maxJokes << '\n';
        }
        
    }
}