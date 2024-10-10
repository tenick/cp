#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    bool isWord = false;
    int curr = 0;
    int currWordLength = 0;
    for (char c : s){
        if (isalpha(c)){
            isWord = true;
        }
        else if (isWord) {
            isWord = false;
            currWordLength = curr;
            curr = 0;
        }

        if (isWord)
            curr++;
    }
    return isWord ? curr : currWordLength;
}

int main(){
    std::string s = "Today is a nice day    ";
    int highest = lengthOfLastWord(s);
    std::cout << "highest: " << highest;
}