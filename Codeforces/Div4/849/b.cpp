#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        int n;
        string s;
        cin >> n >> s;

        int x=0,y=0;
        string result = "NO\n";
        for (char c : s){
            switch(c){
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
            if (x == 1 && y == 1) {
                result = "YES\n";
                break;
            }
        }

        cout << result;
    }
}