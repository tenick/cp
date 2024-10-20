#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string currstr = "";
        for (char c : target) {
            currstr.push_back('a');
            while (currstr.back() != c) {
                ans.push_back(currstr);
                currstr[currstr.size()-1]++;
            }
            ans.push_back(currstr);
        }
        return ans;
    }
};

int main() {}