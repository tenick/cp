#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    sort(arr.begin(), arr.end());


    map<int, int, std::greater<int>> mp;
    for (int i : arr){
        if (mp.find(i) == mp.end()) mp[i] = 0;
        mp[i]++;
    }

    bool found = false;
    vector<int> b;
    vector<int> c;
    for (auto kvp : mp){
        found = true;
        for (auto kvp2 : mp){
            if (kvp.first == kvp2.first) continue;
            if (kvp2.first % kvp.first == 0){
                found = false;
                break;
            }
        }

        if (found){
            for (auto kvp3 : mp){
                if (kvp.first == kvp3.first) continue;

                for (int j = 0; j < kvp3.second; j++)
                    b.push_back(kvp3.first);
            }
            for (int j = 0; j < kvp.second; j++)
                c.push_back(kvp.first);

            break;
        }
    }

    if (!found || b.size() == 0 || c.size() == 0){
        cout << "-1\n";
        return;
    }

    cout << b.size() << " " << c.size() << '\n';
    for (int i : b) cout << i << " ";
    cout << '\n';
    for (int i : c)
        cout << i << " ";
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