#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

// original problem: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

/* implement my idea 1st before proceeding
   my idea: O(n^2) loop to get all possible palindrome substrings of the input string
   precise time complexity: O(n^2(n-1)/2 log n(n-1)/2)
   (you can recall how to do this by solving this: https://leetcode.com/problems/palindromic-substrings/)
   e.g. ababaca, 3
    a b a b a c a
    -> [a b a] found, [a b a b a] found (basically just get all palindromes starting from the ith index of the string)
    b a b a c a
    -> [b a b] found
    a b a c a
    b a c a
    a c a
    c a
    a

    then store all as intervals [a b a] = [0, 2], [a b a b a] = [0, 4], [b a b] = [1, 3]

    then now it's a merge intervals problem: you can recall that try solving the below problem OR by watching the youtube vid explaining it
    https://leetcode.com/problems/non-overlapping-intervals/
*/
int maxPalindromes(std::string s, int k){

    std::vector<std::pair<int, int>> palindromeIntervals;

    // 1. get all palindromes in input string as intervals
    for (int i = 0; i < s.size(); i++){
        int l = i, r = i, length = 1;
        while (l >= 0 && r < s.size()){
            if (s[l] == s[r]){
                if (length >= k)
                    palindromeIntervals.push_back({l, r});
            }
            else break;
            l--;
            r++;
            length += 2;
        } 
    }
    for (int i = 0; i < s.size() - 1; i++){
        int l = i, r = i + 1, length = 2;
        while (l >= 0 && r < s.size()){
            if (s[l] == s[r]){
                if (length >= k)
                    palindromeIntervals.push_back({l, r});
            }
            else break;
            l--;
            r++;
            length += 2;
        } 
    }
    
    for (auto& interval : palindromeIntervals){
        std::cout << "[" << interval.first << ", " << interval.second << "], ";
    }
    std::cout << palindromeIntervals.size() << '\n';

    if (palindromeIntervals.size() == 0)
        return 0;

    // 2. count minimum removal of overlapping intervals to leave only non-overlapping intervals
    std::sort(palindromeIntervals.begin(), palindromeIntervals.end(), [](auto &left, auto &right) {
        return left.first < right.first;
    });


    int removeCount = 0;
    int currEnd = palindromeIntervals[0].second;
    for (int i = 1; i < palindromeIntervals.size(); i++){
        const std::pair<int, int>& interval = palindromeIntervals[i];
        
        if (interval.first <= currEnd){
            if (interval.second < currEnd)
                currEnd = interval.second;
            removeCount++;
        }
        else currEnd = interval.second;
    }

    return palindromeIntervals.size() - removeCount;
    
}

int main(){
    std::string s = "ababaca";
    s = "abaccdbbd";
    s = "fttfjofpnpfydwdwdnns";
    int k = 3;
    k = 1;
    int mp = maxPalindromes(s, k);
    std::cout << mp << '\n';
}