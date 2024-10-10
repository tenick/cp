#include <iostream>
#include <string>

using namespace std;

string preComp = "FBFFBFFBFBFFBFFBFBFFBFFB";
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int k;
        string s;
        cin >> k >> s;

        if (preComp.find(s) == string::npos)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}