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
    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    vector<int> odds;
    vector<int> evens;
    for (int i : nums){
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }
    
    sort(begin(evens), end(evens));
    sort(begin(odds), end(odds));

    int evi = 0;
    int odi = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] % 2 == 0){
            nums[i] = evens[evi];
            evi++;
        }
        else {
            nums[i] = odds[odi];
            odi++;
        }
    }

    for (int i = 0; i < n-1; i++){
        if (nums[i] > nums[i+1]){
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