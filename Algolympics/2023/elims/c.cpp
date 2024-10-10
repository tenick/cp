#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    
    while (t--){
        int k;
        cin >> k;
        string s;
        cin >> s;
        
        bool curr = true;
        int count = 0;

        for (char c : s){
            if (c == '0' && curr){
                curr = false;
                count++;
            }
            if (c == '1' && !curr){
                curr = true;
                count++;
            }
        }
        cout << count << '\n';
    }
}