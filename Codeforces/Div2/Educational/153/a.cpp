#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    string s;
    cin >> s;
    stack<char> st;

    bool valid = true;;
    if (s[0] == ')'){
        valid = false;
    }

    if (valid){
        for (char c : s){
            if (c == '(')
                st.push(c);
            else{
                if (st.empty()){
                    valid = false;
                    break;
                }
                st.pop();
            }
        }
        if (st.size() != 0) valid = false;
    }
    


    if (valid && s.size() == 2){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        bool alternating = true;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1]){
                alternating = false;
                break;
            }
        }

        string ans;
        if (alternating){
            string sleft;
            for (int i = 0; i < s.size(); i++) sleft.push_back('(');
            string sright;
            for (int i = 0; i < s.size(); i++) sright.push_back(')');

            ans.append(sleft);
            ans.append(sright);

        }
        else {
            for (int i = 0; i < s.size(); i++) ans.append("()");
            
        }

        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}