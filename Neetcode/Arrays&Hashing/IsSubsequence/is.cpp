#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    if (s.size() > t.size())
        return false;
    int sC = 0;
    int tC = 0;
    while (sC < s.size() && tC < t.size()){
        sC += t[tC] == s[sC];
        tC++;
    }
    return sC == s.size();
}



int main(){
    std::string s1 = "test";
    std::string s2 = "test2";
    std::cout << isSubsequence(s1, s2);
}
