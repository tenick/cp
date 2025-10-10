class Solution {
public:
    struct VecHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v)
                h ^= hash<int>{}(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
            return h;
        }
    };

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        unordered_set<vector<int>, VecHash> visited;
        int ans = N;
        queue<pair<int, vector<int>>> q;
        q.push({0, nums1});
        visited.insert(nums1);
        while (!q.empty()) {
            auto [ans, curr] = q.front();
            if (curr == nums2) return ans;

            q.pop();

            for (int i = 0; i < N; i++) {
                vector<int> subArr;
                for (int j = i; j < N; j++) {
                    subArr.push_back(curr[j]);

                    vector<int> left;
                    for (int u = 0; u < i; u++) left.push_back(curr[u]);
                    vector<int> right;
                    for (int u = j+1; u < N; u++) right.push_back(curr[u]);

                    for (int k = 0; k <= i; k++) {
                        vector<int> perm;
                        for (int x = 0; x < k; x++) perm.push_back(curr[x]);
                        perm.insert(perm.end(), subArr.begin(), subArr.end());
                        for (int x = k; x < i; x++) perm.push_back(curr[x]);
                        vector<int> arg;
                        arg.insert(arg.end(), perm.begin(), perm.end());
                        arg.insert(arg.end(), right.begin(), right.end());
                        if (visited.find(arg) == visited.end()) {
                            q.push({ans+1, arg});
                            visited.insert(arg);
                        }
                    }

                    for (int k = j+1; k <= N; k++) {
                        vector<int> perm;
                        for (int x = j+1; x < k; x++) perm.push_back(curr[x]);
                        perm.insert(perm.end(), subArr.begin(), subArr.end());
                        for (int x = k; x < N; x++) perm.push_back(curr[x]);
                        vector<int> arg;
                        arg.insert(arg.end(), left.begin(), left.end());
                        arg.insert(arg.end(), perm.begin(), perm.end());
                        if (visited.find(arg) == visited.end()) {
                            q.push({ans+1, arg});
                            visited.insert(arg);
                        }
                    }
                }
            }
        }

        return -1; // impossible to reach here, given the constraints
    }
};

