#include <iostream>
#include <string>
#include <vector>

using namespace std;

int appendCharacters(string s, string t) {
    int ti = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == t[ti]) ti++;
    }
    return t.size() - ti;
}

int main(){
    string s = "z";
    string t = "abcde";
    int ans = appendCharacters(s, t);
    cout << ans << '\n';
}