#include <unordered_map>
#include <stdexcept>
#include <iostream>
using namespace std;

inline bool assert(bool res){
    if (!res)
        throw std::invalid_argument("assert failed");
    std::cout << "passed\n";
}

bool isAnagram(string s, string t) {
    unordered_map<char, int> x;
    unordered_map<char, int> y;
    
    for (char c : s){
        if (x.find(c) != x.end())
            x[c]++;
        else
            x[c] = 1;
    }
    
    for (char c : t){
        if (y.find(c) != y.end())
            y[c]++;
        else
            y[c] = 1;
    }
    return x == y;
}

int main(){
    assert(isAnagram("anagram", "nagaram") == true);
    assert(isAnagram("rat", "car") == false);
}