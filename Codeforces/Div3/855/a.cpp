#include <iostream>
#include <string>

using namespace std;

string meow = "meow";

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;

        int ind = 0;
        bool isCat = true;
        bool changed = false;
        char curr = 'm';
        for (int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);

            if (curr != s[i]){
                ind++;
                if (ind >= 4){
                    isCat = false;
                    break;
                }
                curr = meow[ind];
                if (curr != s[i]){
                    isCat = false;
                    break;
                }
            }
        }
        
        if (s[0] != 'm' || ind != 3) isCat = false;

        if (isCat)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}