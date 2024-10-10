#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n, k;
        string s, t;
        cin >> n >> k >> s >> t;

        vector<int> sChars(26);
        vector<int> tChars(26);

        for (char c : s)
            sChars[c-'a']++;

        for (char c : t)
            tChars[c-'a']++;

        bool isAnagram = true;
        for (int i = 0; i < 26; i++){
            if (sChars[i] != tChars[i]){
                isAnagram = false;
                break;
            }
        }

        if (!isAnagram){
            cout << "NO\n";
            continue;
        }

        bool possible = true;
        for (int i = 0; i < n; i++){
            if (s[i] != t[i]){
                if (i - k < 0 && i + k > n - 1){
                    possible = false;
                    break;
                }
            }
        }

        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
}
