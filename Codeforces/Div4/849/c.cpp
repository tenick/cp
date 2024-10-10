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

        int l=0, r=n-1;
        while (l < r){
            if (s[l] == s[r]) break;
            l++; r--;
        }
        cout << r - l + 1 << '\n';
    }
}