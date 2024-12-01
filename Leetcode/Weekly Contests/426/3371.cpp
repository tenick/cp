class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        multiset<int> ms;
        int sm = 0;
        for (int i : nums) {
            ms.insert(i);
            sm+=i ;
        }
        int ans = INT_MIN;
        for (int i : nums) {
            ms.erase(ms.find(i));
            sm -= i;
            if (sm % 2 == 0 && ms.find(sm/2) != ms.end()){
                ans = max(ans, i);
            }
            sm += i;
            ms.insert(i);
        }
        return ans;
    }
};
