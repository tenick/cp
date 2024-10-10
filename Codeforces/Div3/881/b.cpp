#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

typedef unsigned long long ull;

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> elems(n);
    for (int& i : elems) cin >> i;

    int minOp = 0;
    ull maxSum = 0;
    bool inSeq = false;
    for (int i : elems){
        if (i <= 0){
            if (!inSeq && i != 0){
                inSeq = true;
                minOp++;
            }
        }
        else inSeq = false;

        maxSum += abs(i);
    }
    cout << maxSum << " " << minOp << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}