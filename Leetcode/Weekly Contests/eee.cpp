#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

#define MAXCOST 1000001

class Solution {
public:
    int minCostF(int s, int e, vector<int> cuts, unordered_map<pair<int, int>, int, pairhash>* seByAnsMemo){
        pair<int, int> se{s, e};
        if (seByAnsMemo->find(se) != seByAnsMemo->end())
            return (*seByAnsMemo)[se];
        //cout << "s: " << s << "; e: " << e << '\n';
        //for (int cut : cuts) cout << cut << " ";
        //cout << '\n';

        if (cuts.size() == 0){
            (*seByAnsMemo)[se] = 0;
            return 0;
        }

        if (cuts.size() == 1){
            (*seByAnsMemo)[se] = e - s;
            return e - s;
        }


        int minTotalCost = e - s;
        int minRecurseCost = MAXCOST;

        for (int i = 0; i < cuts.size(); i++){
            int totalRecurse = 0;

            //cout << "recurse left of cut: " << cuts[i] << '\n';
            vector<int> left;
            copy(cuts.begin(), cuts.end() - (cuts.size() - i ), back_inserter(left));
            totalRecurse += minCostF(s, cuts[i], left, seByAnsMemo);
            
            //cout << "recurse right of cut: " << cuts[i] << '\n';
            vector<int> right;
            copy(cuts.begin() + (i + 1), cuts.end(), back_inserter(right));
            totalRecurse += minCostF(cuts[i], e, right, seByAnsMemo);

            //cout << "\n" << totalRecurse << " total recurse of " << cuts[i] << " from s: " << s << " to e: " << e << '\n'; 
            minRecurseCost = min(minRecurseCost, totalRecurse);
        }

        (*seByAnsMemo)[se] = minTotalCost + minRecurseCost;
        return (*seByAnsMemo)[se];
    }

    int minCost(int n, vector<int>& cuts) {
        unordered_map<pair<int, int>, int, pairhash>* seByAnsMemo = new unordered_map<pair<int, int>, int, pairhash>;
        sort(cuts.begin(), cuts.end());
        int minAns = minCostF(0, n, cuts, seByAnsMemo);
        //cout << "final map size: " << seByAnsMemo->size();
        return minAns;
    }
};

int main(){
    
}