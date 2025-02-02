class Solution {
public:
    int maxDifference(string s) {
        map<char, int> fc;
        for (char c : s) {
            if (fc.find(c) == fc.end())
                fc[c]=0;
            fc[c]++;
        }
        int mxodd = 0, mneven = 500;
        for (auto& kvp : fc) {
            if (kvp.second % 2 == 0)
                mneven = min(mneven, kvp.second);
            else
                mxodd= max(mxodd, kvp.second);
        }
        return mxodd - mneven;
    }
};
