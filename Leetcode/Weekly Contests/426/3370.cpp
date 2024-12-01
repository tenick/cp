class Solution {
public:
    int smallestNumber(int n) {
        int c = 1;
        int ans = 0;
        while (ans <= n) {
            ans += c;
            if (ans == n) break;
            c *= 2;
        }
        return ans;
    }
};
