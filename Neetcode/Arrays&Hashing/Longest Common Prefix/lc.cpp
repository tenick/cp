#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    int strI = 0;
    std::string longestPrefix = "";
    
    while (true){
        if (strI >= strs[0].length()) break;
        
        bool done = false;
        char toAdd = strs[0][strI];
        
        for (int i = 1; i < strs.size(); i++){
            if (toAdd != strs[i][strI]){
                done = true;
                break;
            }
        }
        
        if (done) break;
        
        longestPrefix.push_back(toAdd);
        strI++;
    }
    
    return longestPrefix;
}

int main(){
    std::vector<std::string> strs {"flower","flow","flight"};
    std::cout << longestCommonPrefix(strs);
}