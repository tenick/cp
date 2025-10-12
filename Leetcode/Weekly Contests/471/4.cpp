typedef long long ll;

int primes[] {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313
};
    
class Solution {
public:
    ll factorize(int x) {
        ll f = 1;
        int i = 0;
        while (x > 1 && i < 65) {
            int cnt = 0;
            while (x % primes[i] == 0) {
                x /= primes[i];
                cnt++;
            }
            if (cnt % 2 == 1) f *= primes[i];
            i++;
        }
        if (i == 65)
            f *= x;
        return f;
    }

    ll rcway(int node, int parent, unordered_map<ll, int>& seen, vector<vector<int>>& nodesByEdges, vector<int>& nums) {
        auto hashed = factorize(nums[node]);
        seen[hashed]++;
        ll ans = seen[hashed]-1;
        for (int child : nodesByEdges[node]) {
            if (child == parent) continue;
            ans += rcway(child, node, seen, nodesByEdges, nums);
        }
        seen[hashed]--;
        return ans;
    }
    
    ll sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> nodesByEdges(n);
        for (auto& edge : edges) {
            nodesByEdges[edge[0]].push_back(edge[1]);
            nodesByEdges[edge[1]].push_back(edge[0]);
        }
        unordered_map<ll, int> seen;
        return rcway(0, -1, seen, nodesByEdges, nums);
    }
};

