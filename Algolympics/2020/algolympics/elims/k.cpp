#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<bool> mks(n);
        for (int i = 0; i < n; i++){
            string s;
            cin >> s;
            if (s == "MOOK") mks[i] = true;
        }
        int count = 0;
        for (int i = 0; i < n; i++){
            if (mks[i]){
                for (int j = 0; j <= i; j++){
                    mks[j] = !mks[j];
                }
                i = -1;
                count++;
            }
        }
        cout << count << '\n';
    }
}
