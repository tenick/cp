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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n);
    for (int& i : a) cin >> i;
    for (int& i : c) cin >> i;
    vector<int> freq(n, 0);
    for (int i : a){
        freq[i-1]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (freq[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        freq[a[curr]-1]--;
        if (freq[a[curr]-1] == 0){
            q.push(a[curr]-1);
        }
        ans.push_back(curr+1);
    }
    for (int i = 0; i < n; i++){
        if (freq[i] == 0) continue;
 
        int mini = i;
        int mincost = 1e9+1;
        int curr = i;
        vector<int> inds;
        while (freq[curr]){
            int next = a[curr]-1;
            int cost = c[curr];
            if (cost < mincost){
                mincost = cost;
                mini = curr;
            }
            freq[curr]--;
            curr = next;
            inds.push_back(curr);
        }
        vector<int> temp;
        int stopped = -1;
        for (int j = 0; j < inds.size(); j++){
            int val = inds[j];
            if (val == a[mini]-1) {
                stopped = j;
                break;
            }
            temp.push_back(val+1);
        }
        vector<int> temp2;
        for (int j = stopped; j < inds.size(); j++){
            temp2.push_back(inds[j]+1);
        }
        ans.insert(ans.end(), temp2.begin(), temp2.end());
        if (temp.size() != 0) ans.insert(ans.end(), temp.begin(), temp.end());
    }
    
    for (int i : ans) cout << i << ' ';
    cout << '\n';
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