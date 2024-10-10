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
    vector<int> t(3);
    cin >> t[0] >> t[1] >> t[2];

    bool possible = false;
    for (int i = 0; i < 3; i++){
        int fixed = t[i];
        bool possible2 = true;

        vector<int> vals;
        for (int j = 0; j < 3; j++){
            if (j == i) continue;

            int curr = t[j];
            if (curr < fixed){
                possible2 = false;
                break;
            }
            vals.push_back(curr);
        }


        if (possible2){
            if (fixed == vals[0] && fixed == vals[1]){
                possible = true;
                break;
            }

            if (fixed == vals[0] && (fixed * 2 == vals[1] || fixed * 3 == vals[1] || fixed * 4 == vals[1])){
                possible = true;
                break;
            }

            if (fixed == vals[1] && (fixed * 2 == vals[0] || fixed * 3 == vals[0] || fixed * 4 == vals[0] )){
                possible = true;
                break;
            }

            // below means no val equals fixed
            int v1 = vals[0] - fixed;
            int v2 = vals[1] - fixed;
            if (v1 != fixed && v2 != fixed){
                continue;
            }
            if (v1 == fixed && v2 == fixed){
                possible = true;
                break;
            }
            else {
                if (v1 != fixed && v1 == fixed * 2){
                    possible = true;
                    break;
                }
                if (v2 != fixed && v2 == fixed * 2){
                    possible = true;
                    break;
                }
            }
        }
    }
    if (possible){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

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