#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> apples(n);
    vector<int> trees(n);
    for (int& i : apples) cin >> i;
    for (int& i : trees) cin >> i;

    vector<vector<int>> segs;
    int prev = trees[0];
    vector<int> seg;
    for (int i = 0; i < trees.size(); i++){
        int val = trees[i];
        if (prev % val == 0){
            seg.push_back(i);
            prev = val;
        }
        else {
            prev = val;
            i--;
            segs.push_back(seg);
            seg.clear();
        }
    }
    segs.push_back(seg);

    int maxans = 0;
    for (auto& seg : segs){
        int sum = 0;
        int l = -1, r = 0;
        while (r < seg.size()){
            sum += apples[seg[r]];
            if (sum <= k){
                maxans = max(maxans, r - l);
                r++;
            }
            else {
                while (sum > k){
                    l++;
                    sum = sum - apples[seg[l]];
                }
                r++;
            }
        }
    }
    cout << maxans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}