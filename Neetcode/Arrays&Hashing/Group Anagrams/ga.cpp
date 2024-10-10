#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iterator>

std::vector<std::vector<std::string>> groupAnagramsApproach2(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> words;
    
    for (std::string str : strs){

        std::ostringstream oStr;
        
        std::vector<int> alphaCount(26);
        for (char c : str){
            int subtrVal = isupper(c) ? 65 : 97;
            alphaCount[c - subtrVal] += 1;
        }
        
        std::copy(alphaCount.begin(), alphaCount.end(), std::ostream_iterator<int>(oStr, "#"));
        
        std::string hashKey = oStr.str();

        if (words.find(hashKey) == words.end())
            words[hashKey] = { str };
        else words[hashKey].push_back(str);
    }

    std::vector<std::vector<std::string>> anagrams;
    for (auto& it : words){
        anagrams.push_back(it.second);
    }
    return anagrams;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> words;
    
    for (std::string str : strs){
        std::string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        if (words.find(sortedStr) == words.end())
            words[sortedStr] = { str };
        else words[sortedStr].push_back(str);
    }

    std::vector<std::vector<std::string>> anagrams;
    for (auto& it : words){
        anagrams.push_back(it.second);
    }
    return anagrams;
}

int main() {
    std::vector<std::string> words {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> res = groupAnagramsApproach2(words);
    for (std::vector<std::string> anagram : res){
        for (std::string s : anagram){
            std::cout << s << ',';
        }
        std::cout << '\n';
    }
}