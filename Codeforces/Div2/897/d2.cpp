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
    vector<int> b(n);
    for(int& i : b) cin >> i;

    if (k == 1){
        for (int i = 0; i < n; i++){
            if (b[i] != i + 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }

    vector<int> visited(n);
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;

        int start = i, loc = i;
        int len = 0;

        vector<int> inds;
        while(!visited[loc]){
            len++;
            inds.push_back(loc);
            visited[loc] = len;
            loc = b[loc]-1;
            if (visited[loc]){
                if (find(begin(inds), end(inds), loc) != inds.end()){
                    len -= visited[loc]-1;
                    visited[loc] = len;
                }
                else len = visited[loc];
                break;
            }
        }
        for (int j : inds) visited[j] = len;
    }

    for (int i : visited){
        if (i != k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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