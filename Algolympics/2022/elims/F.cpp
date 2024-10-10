#include <iostream>
#include <unordered_map>
#include <algorithm>

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
 
std::string a, b;

int maxReverse(int s, int e, std::unordered_map<std::pair<int, int>, int, pair_hash>& memo){
    std::pair<int, int> SE;
    SE.first = s;
    SE.second = e;
    if (memo.count(SE))
        return memo[SE];
    if (s > e)
        return 0;
    if (s == e)
        return a[s] == b[e];

    bool s1 = a[s] == b[s];
    bool e1 = a[e] == b[e];
    if (s1 || e1){
        memo[SE] = s1 + e1 + maxReverse(s + s1, e - e1, memo);
        return memo[SE];
    }
    else{
        int length = e - s + 1;
        int lengthCopy = length;
        for (int i = 0; i < lengthCopy; ++i)
            if (a[s + i] != b[e - i])
                length--;
        if (length == e - s + 1){
            memo[SE] = length;
            return memo[SE];
        }
        
        memo[SE] = std::max({length, maxReverse(s, e - 1, memo), maxReverse(s + 1, e, memo)});
        return memo[SE];
    }
}

int main(){
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++){
        std::cin >> a >> b;
        std::unordered_map<std::pair<int, int>, int, pair_hash> memo;
        
        std::cout << maxReverse(0, a.length() - 1, memo) << '\n';
    }
}
