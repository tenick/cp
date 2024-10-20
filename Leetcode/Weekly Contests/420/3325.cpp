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
    int numberOfSubstrings(string s, int k) {
        int l = 0, r = 0, ans = 0;;
        vector<int> freq(26);
        while (r < s.size()) {
            int i = s[r]-'a';
            freq[i]++;
            while (freq[i] == k) {
                ans += s.size() - r;
                int j = s[l]-'a';
                freq[j]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};

int main() {}