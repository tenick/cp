#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        string a, b;
        cin >> a >> b;
        
        bool matchFirst = false;
        bool matchLast = false;
        bool twoConsecutiveMatch = false;
        string matchStr;
        
        matchFirst = a[0] == b[0];
        matchLast = a[a.size()-1] == b[b.size()-1];
        if (matchFirst) {
            cout << "YES\n";
            cout << a[0] << '*' << '\n';
            continue;
        }
        if (matchLast){
            cout << "YES\n";
            cout << '*' << a[a.size()-1] << '\n';
            continue;
        }
        
        for (int i = 0; i < a.size()-1; i++){
            string toFind = a.substr(i, 2);
            int match = b.find(toFind);
            if (match != string::npos){
                twoConsecutiveMatch = true;
                matchStr = toFind;
                break;
            }
        }

        if (twoConsecutiveMatch){
            cout << "YES\n";
            cout << '*' << matchStr << '*' << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
}