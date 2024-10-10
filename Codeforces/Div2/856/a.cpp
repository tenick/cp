#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int j = 0; j < t; j++){
        int n;
        cin >> n;
        
        int len = 2*n-2;
        string s1;
        string s2;

        int halfLen = n / 2 + (n % 2 == 1);

        vector<string> strs;
        for (int i = 0; i < len; i++){
            string curr;
            cin >> curr;
            strs.push_back(curr);
        }

        for (string& curr : strs){
            if (curr.size() == halfLen){
                if (s1.size() == 0) s1 = curr;
                else {
                    s2 = curr; 
                    break;
                }
            }
        }

        reverse(s2.begin(), s2.end());
        if (s1 == s2) cout << "YES\n";
        else cout << "NO\n";
    }
}