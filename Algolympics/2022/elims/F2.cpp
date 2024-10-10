#include <iostream>
#include <vector>
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

int maxReverse(){
    int maxReverseVal = 0;
    std::vector<std::unordered_map<std::pair<int, int>, std::pair<int, int>*, pair_hash>> memos;
    for (int i = 0; i < a.length(); i++)
        memos.push_back(std::unordered_map<std::pair<int, int>, std::pair<int, int>*, pair_hash>());
    
    for (int i = 0; i < a.length(); i++){
        for (int j = 0 ; j < i + 1; j++){
            int s = j;
            int e = j + a.length() - i - 1;

            bool L1 = a[s] == b[s];
            bool L2 = a[e] == b[e];
            bool oppL1 = a[s] == b[e];
            bool oppL2 = a[e] == b[s];

            std::pair<int, int> SE (s, e);
            std::pair<int, int> outSE (s - 1, e + 1);
            
            if (s - 1 >= 0 && e + 1 < a.length() && e - s + 2 < a.length() && memos[e - s + 2].find(outSE) != memos[e - s + 2].end() && memos[e - s + 2][outSE] != nullptr){
                std::pair<int, int> update = std::pair<int, int>(*memos[e - s + 2][outSE]);
                update.first += oppL1 + oppL2;
                update.second += L1 + L2;
                if (update.second >= update.first)
                    memos[e - s + 2][outSE] = nullptr;
                else
                    memos[e - s][SE] = new std::pair<int, int> (update);
                
                if (e - s == 1 || e - s == 0)
                    if (update.first - update.second > maxReverseVal)
                        maxReverseVal = update.first - update.second;
            }
            else if ((oppL1 || oppL2) && !(L1 && L2)){
                std::pair<int, int> newMemo (oppL1 + oppL2, L1 + L2);
                memos[e - s][SE] = new std::pair<int, int> (newMemo);

                if (e - s == 1 || e - s == 0)
                    if (newMemo.first - newMemo.second > maxReverseVal)
                        maxReverseVal = newMemo.first - newMemo.second;
            }
        }
    }

    for (int i = 0; i < a.length(); i++){
        if (a[i] == b[i])
            maxReverseVal++;
    }
    return maxReverseVal;
}

int main(){
    int t;
    std::cin >> t;

    for (int _ = 0; _ < t; _++){
        std::cin >> a >> b;
        std::cout << maxReverse() << '\n';
    }
}
