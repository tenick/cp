#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n, k;
        string s;

        cin >> n >> k >> s;
        
        vector<stack<char>> burlStacks(26);

        int burls = 0;
        for (int i = 0; i < n; i++){
            int ind = s[i] - 'a';
            bool isUpper = ind < 0;
            if (isUpper) ind = s[i] - 'A';

            stack<char>& burlStack = burlStacks[ind];
            if (burlStack.size() > 0){
                char top = burlStack.top();
                bool topIsUpper = top - 'a' < 0;
                if (topIsUpper != isUpper){
                    burls++;
                    burlStack.pop();
                }
                else burlStack.push(s[i]);
            }
            else burlStack.push(s[i]);
        }

        for (stack<char>& burlStack : burlStacks){
            if (k == 0) break;
            int canAdd = burlStack.size() / 2;
            int finalAdd = min(k, canAdd);
            k -= finalAdd;
            burls += finalAdd;
        }
        
        cout << burls << '\n';
    }
}