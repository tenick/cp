#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;

        int count = 1;
        for (int i = 0; i < n-2; i++){
            char c1 = s[i];
            char c2 = s[i+2];
            if (c1 != c2) count++;
        }
        
        cout << count << '\n';
    }
}