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

    vector<pair<int, bool>> simpleArr;
    bool inZeroes = arr[0] == 0;
    int cnt = 0;
    int maxNonZero = 1;
    for (int x : arr){
        if (inZeroes){
            if (x == 0){
                cnt++;
            }
            else {
                simpleArr.push_back({cnt, inZeroes});
                maxNonZero = x;
                inZeroes = false;
                cnt = 1;
            }
        }
        else {
            if (x == 0){
                simpleArr.push_back({maxNonZero, inZeroes});
                cnt = 1;
                inZeroes = true;
            }
            else {
                maxNonZero = max(maxNonZero, x);
            }
        }
    }
    simpleArr.push_back({inZeroes ? cnt : maxNonZero, inZeroes});

    int minCoins = 0;
    for (int i = 0; i < simpleArr.size(); i++){
        auto& p = simpleArr[i];
        
        bool inZeroes = p.second;

        if (inZeroes){
            int cnt = p.first;
            minCoins += cnt;
            //cout << "inzeroes: coins: " << minCoins << '\n';
        }
        else {
            minCoins++;
            //cout << "not inzeroes: coins: " << minCoins << '\n';
            int maxNonZero = p.first;
            int back = i-1;
            int front = i+1;
            if (maxNonZero > 0 && back >= 0){
                if (simpleArr[back].first != 0){
                    simpleArr[back].first--;
                    minCoins--;
                    maxNonZero--;
                }
            }
            if (maxNonZero > 0 && front < simpleArr.size()){
                if (simpleArr[front].first != 0){{
                    minCoins += simpleArr[front].first;
                    simpleArr[front].first--;
                    minCoins--;
                    maxNonZero--;
                    i++;
                }}
            }
            //cout << "not inzeroes: new coins: " << minCoins << '\n';
        }
    }

    cout << minCoins << '\n';
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}