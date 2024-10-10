#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;

        string a;
        string b;
        unordered_map<char, int> kmap;
        cin >> a >> b;

        vector<int> ps(1);
        for (int i = 0; i < n; i++){
            ps.push_back(ps.back() + (a[i] == b[i]));
            cout << ps[i+1] << " ";
        }
        cout << '\n';

        int l=0, r=0,maxs=0, currK=0;
        while (r != n){
            if (currK > k){
                if (k == 0) {
                    r++;
                    l = r;
                    currK = 0;
                    continue;
                }
                if (a[l] != b[l]) {
                    kmap[a[l]]--;
                    if (kmap[a[l]] == 0){
                        kmap.erase(a[l]);
                        currK--;
                    }
                }
                l++;
            }
            else {
                if (a[r] != b[r]){
                    if (kmap.find(a[r]) == kmap.end()){
                        if (currK == k){
                            currK++;
                            continue;
                        }
                        kmap[a[r]] = 0;
                        currK++;
                    }
                    kmap[a[r]]++;
                }
                maxs = max(maxs, r - l + 1);
                r++;
            }
        }

        cout << maxs * (maxs+1) / 2 << '\n';
    }

}