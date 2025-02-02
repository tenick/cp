class Solution {
public:
    vector<pair<char, char>> opps {
        {'S', 'N'},
        {'N', 'S'}, 
        {'W', 'E'}, 
        {'E', 'W'} 
    };
    int maxDistance(string s, int k) {
        map<char, int> mc;
        for (char c : s) {
            if (mc.find(c) == mc.end())
                mc[c]=0;
            mc[c]++;
        }
        int bestans = 0;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 4; j++) {
                if (i == j || opps[i].first == opps[j].second)
                    continue;
                auto d1 = opps[i].first;
                auto d2 = opps[j].first;
                vector<int> toslide;
                for (char c : s) {              
                    bool res = d1 == c || d2 == c;
                    toslide.push_back(res);
                }
                int l = 0, r = 0, bcnt=0, perm=0, ans = 0;
                while (r < s.size()) {
                    while (bcnt > k) {
                       if (!toslide[l]) {
                           bcnt--;
                           perm--;
                       } else perm++;
                       l++;
                    } 
                    ans = max(ans, r - l + perm);
                    if (!toslide[r]) bcnt++;
                    r++;
                }
                while (bcnt > k) {
                   if (!toslide[l]) {
                       bcnt--;
                       perm--;
                       } else perm++;
                   l++;
                } 
                ans = max(ans, r - l + perm);
                bestans = max(bestans, ans);
            }
        }
        return bestans;
    }
};
