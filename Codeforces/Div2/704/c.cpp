#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;

    string s;
    cin >> s;
    string t;
    cin >> t;

    vector<int> minT(m);
    vector<int> maxT(m);

    int currT = 0;
    for (int i = 0; i < n; i++){
        if (currT == m) break;
        if (t[currT] == s[i]){
            minT[currT] = i;
            currT++;
        }
    }

    currT = m - 1;
    for (int i = n - 1; i >= 0; i--){
        if (currT == -1) break;
        if (t[currT] == s[i]){
            maxT[currT] = i;
            currT--;
        }
    }

    int maxWidth = 0;
    for (int i = 0; i < m - 1; i++){
        maxWidth = max(maxWidth, maxT[i + 1] - minT[i]);
    }
    
    cout << maxWidth << '\n';
}