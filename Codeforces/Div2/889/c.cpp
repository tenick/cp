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
    
    bool allzero = true;
    for (int i : arr){
        if (i != 0){
            allzero = false;
            break;
        }
    }

    if (allzero){
        cout << 0 << '\n';
        return;
    }

    // find max from 0
    int maxfrom0 = 0;
    int ind = 0;
    for (int i = 0; i < n; i++){
        if (abs(arr[i]) > abs(maxfrom0)){
            maxfrom0 = arr[i];
            ind = i;
        } 
    }


    vector<pair<int, int>> operations;
    if (maxfrom0 < 0) {
        while (maxfrom0 > -20){
            maxfrom0 += maxfrom0;
            operations.push_back({ind+1, ind+1});
        }
        arr[ind] = maxfrom0;
        for (int i = 0; i < n; i++){
            if (arr[i] > 0){
                operations.push_back({i+1, ind+1});
            }
        }
        arr[n-1] += maxfrom0;
        operations.push_back({n, ind+1});

        for (int i = n-1; i > 0; i--){
            arr[i-1] += arr[i];
            operations.push_back({i, i+1});
        }
    }
    else {
        while (maxfrom0 < 20){
            maxfrom0 += maxfrom0;
            operations.push_back({ind+1, ind+1});
        }
        arr[ind] = maxfrom0;
        for (int i = 0; i < n; i++){
            if (arr[i] < 0){
                operations.push_back({i+1, ind+1});
            }
        }
        arr[0] += maxfrom0;
        operations.push_back({1, ind+1});

        for (int i = 0; i < n-1; i++){
            arr[i+1] += arr[i];
            operations.push_back({i+2, i+1});
        }
    }

    cout << operations.size() << '\n';
    for (auto op : operations){
        cout << op.first << " " << op.second << '\n';
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