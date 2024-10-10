#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool inSeg = false;
    bool pie = false;
    int prev = 0;
    string u1 = "pie";
    string u2 = "map";
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (inSeg){
            if (pie){
                if (s[i] == u1[prev]){
                    if (prev == 2){
                        cnt++;
                        inSeg = false;
                    }
                    prev++;
                }
                else {
                    if (s[i] == 'm'){
                        inSeg = true;
                        pie = false;
                        prev = 1;
                    }
                    else if (s[i] == 'p'){
                        inSeg = true;
                        pie = true;
                        prev = 1;
                    }
                    else inSeg = false;
                }
            }
            else {
                if (s[i] == u2[prev]){
                    if (prev == 2){
                        cnt++;
                        inSeg = false;
                    }
                    prev++;
                }
                else {
                    if (s[i] == 'm'){
                        inSeg = true;
                        pie = false;
                        prev = 1;
                    }
                    else if (s[i] == 'p'){
                        inSeg = true;
                        pie = true;
                        prev = 1;
                    }
                    else inSeg = false;
                }
            }
        }
        else {
            if (s[i] == 'm'){
                inSeg = true;
                pie = false;
                prev = 1;
            }
            else if (s[i] == 'p'){
                inSeg = true;
                pie = true;
                prev = 1;
            }
        }
    }
    cout << cnt << '\n';
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