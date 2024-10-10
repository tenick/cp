#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> permProd(vector<int>& v1, vector<int>& v2){
    vector<int> r(v1.size());
    for (int i = 0; i < v1.size(); i++){
        r[i] = v2[v1[i] - 1];
    }
    return r;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    vector<int> test(1000000, 5);
    for (int i = 0; i < 1000000; i++) test[i] = 2;
    cout << test[532423] << " test\n";
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> perms(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> perms[i][j];
            }
        }

        
        auto cmp = [](const auto& v1, const auto& v2){
            bool ans = false;
            for (int i = 1; i <= v1.size(); i++){
                bool orToAdd = true;
                for (int j = 0; j < i; j++){
                    if (j == i - 1)
                        orToAdd &= v1[j] < v2[j];
                    else orToAdd &= v1[j] <= v2[j];
                    if (!orToAdd) break;
                }
                ans |= orToAdd;
                if (ans) break;
            }
            return ans;
        };

        sort(perms.begin(), perms.end(), cmp);

        cout << '\n';
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++){
                cout << perms[i][k] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //         vector<int> r = permProd(perms[i], perms[j]);
        //         cout << "a" << i+1 << " * " << "a" << j+1  << " = r" << i+1 << "," << j+1 << ": ";
        //         for (int k : r){
        //             cout << k << " ";
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }
    }
}
// 3 1 4 2
