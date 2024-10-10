#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> partisByTTS(n, vector<int>(m));
    vector<vector<int>> partisByPtsAndPenalty;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> partisByTTS[i][j];
        }
        sort(partisByTTS[i].begin(), partisByTTS[i].end());
        int pts = 0;
        int penalty = 0;
        int currTime = 0;
        for (int k = 0; k < m; k++){
            currTime += partisByTTS[i][k];
            if (currTime <= h){
                pts++;
                penalty += currTime;
            }
        }
        partisByPtsAndPenalty.push_back({pts, penalty, i});
    }
    // this comparator will sort column 1, THEN column 2
    sort(begin(partisByPtsAndPenalty), end(partisByPtsAndPenalty),
    
    [&](const auto &a, const auto &b)
    {
      return a[0] > b[0] || (!(b[0] > a[0]) && a[1] < b[1]);
// if for 3 columns, return a[0] < b[0] || (a[0] <= b[0] && a[1] < b[1]) || (a[0] <= b[0] && a[1] <= b[1] && a[2] < b[2])	
    });

    for (int i = 0; i < n; i++){
        if (partisByPtsAndPenalty[i][2] == 0){
            cout << (i+1) << '\n';
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}

