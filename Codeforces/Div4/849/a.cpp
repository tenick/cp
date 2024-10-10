#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    string s = "codeforces";
    while (t--){
        char c;
        cin >> c;

        if (s.find(c) != string::npos)
            cout << "YES\n";
        else cout << "NO\n";
    }
}