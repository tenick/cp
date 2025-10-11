typedef long long ll;
template <typename T>
constexpr T log_b(T x, T base=2) {
    return std::log(x) / std::log(base);
}

class sparse_table {
private:
    vector<vector<int>> m_st;
    function<int(int,int)> f;
public:
    sparse_table(const vector<int>& arr, bool minQ = true) {
        int n = arr.size();
        int LOG = log_b(n)+1;
        m_st.assign(n, vector<int>(LOG));

        f = minQ ? [](int a,int b){return min(a,b);}
                 : [](int a,int b){return max(a,b);};

        for (int i = 0; i < n; i++) m_st[i][0] = arr[i];
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n - (1 << (j-1)); i++)
                m_st[i][j] = f(m_st[i][j-1], m_st[i+(1 << (j-1))][j-1]);
    }

    int query(int l, int r) {
        int lg = log_b(r-l+1);
        return f(m_st[l][lg], m_st[r-(1 << lg)+1][lg]);
    }
};
class Solution {
public:
    ll numsIsSortedVariation(vector<int>& nums, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) pq.push({nums[i] - nums.back(), i, nums.size()-1});
        ll ans = 0;
        while (!pq.empty() && k != 0) {
            auto [diff, l, r] = pq.top();
            pq.pop();
            ans += diff;
            if (l < r)
                pq.push({nums[l] - nums[--r], l, r});
            k--;
        }
        return ans;
    }
    
    ll maxTotalValue(vector<int>& nums, int k) {
        sparse_table stMin = sparse_table(nums), stMax = sparse_table(nums, false);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) pq.push({stMax.query(i, nums.size()-1) - stMin.query(i, nums.size()-1), i, nums.size()-1});
        ll ans = 0;
        while (!pq.empty() && k != 0) {
            auto [diff, l, r] = pq.top();
            pq.pop();
            ans += diff;
            if (l < r)
                pq.push({stMax.query(l, --r) - stMin.query(l, r), l, r});
            k--;
        }
        return ans;
    }
};

