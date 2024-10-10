#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        int n, q;
        cin >> n >> q;
        vector<int> ints(n);
        set<int> inds;
        for (int i = 0; i < n; i++){
            inds.insert(i);
            cin >> ints[i];
        }
        inds.insert(n);
        
        for (int i = 0; i < q; i++){
            int query;
            cin >> query;
            if (query == 1){
                int l, r;
                cin >> l >> r;
                l--;r--;
                l = *inds.lower_bound(l);
                while (l <= r){
                    int currn = ints[l] % 10;
                    int curr = ints[l] / 10;
                    while (curr != 0){
                        currn += curr % 10;
                        curr /= 10;
                    }
                    if (ints[l] < 10) inds.erase(l);
                    ints[l] = currn;

                    l++;
                    l = *inds.lower_bound(l);
                }
            }
            else {
                int x;
                cin >> x;
                cout << ints[x-1] << '\n';
            }
        }
    }
}