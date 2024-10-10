#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    vector<int> charCount(26, 0);
    for (char c : s) charCount[c - 65]++;

    int oddCount = 0;
    for (int i : charCount) oddCount += i % 2 == 1;

    if (oddCount > 1 && s.size() % 2 == 1 || oddCount > 0 && s.size() % 2 == 0)
        cout << "NO SOLUTION\n";
    else {
        string ans;
        ans.reserve(s.size());
        char oddC = 0;
        for (int i = 0; i < charCount.size(); i++){
            char c = i + 65;
            if (charCount[c - 65] % 2 == 1)
                oddC = c;
            ans += string(charCount[c - 65] / 2, c);
        }
        if (oddC != 0) ans.push_back(oddC);
        for (int i = charCount.size() - 1; i >= 0; i--){
            char c = i + 65;
            ans += string(charCount[c - 65] / 2, c);
        }
        cout << ans << '\n';
    }
}