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

int cntBig(int bigger, int sameVal){
    int tosub = bigger-sameVal;
    return (bigger * (bigger+1) / 2) - (tosub * (tosub + 1) / 2);
}

void solve(){
    int n;
    cin >> n;

    int bn = n * (n-1) / 2;
    vector<int> b(bn);
    for (int& i : b) cin >> i;

    map<int, int, std::greater<int>> cnt;
    for (int i : b){
        if (cnt.find(i) == cnt.end()) cnt[i] = 0;
        cnt[i]++;
    }

    vector<int> orig;
    int biggerCnt = 0;
    for (auto& kvp : cnt){
        int sameAdded = 1;
        while (kvp.second > cntBig(biggerCnt, sameAdded)){
            biggerCnt++;
            orig.push_back(kvp.first);
            sameAdded++;
        }
        orig.push_back(kvp.first);
        biggerCnt++;
    }

    for (int i : orig) cout << i << ' ';
    cout <<'\n';
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