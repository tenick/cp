#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

bool isThereGoodSegment(vector<pair<int, int>>& segments, int prefLen, int changeInd, vector<int>& changes){
    vector<int> arrPrefix(prefLen);
    for (int i = 0; i <= changeInd; i++){
        arrPrefix[changes[i]-1] = 1;
    }
    int total = 0;
    for (int& i : arrPrefix){
        if (i == 1) total++;
        i = total;
    }

    // check if there is good segment
    bool theresGoodSegment = false;
    for (auto& segment : segments){
        int start = segment.first-1;
        int end = segment.second-1;
        int segLen = end - start + 1;
        int ones = arrPrefix[end] - (start-1 >= 0 ? arrPrefix[start-1] : 0);
        if (ones > segLen - ones){
            theresGoodSegment = true;
            break;
        }
    }
    return theresGoodSegment;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segments;
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }
    int q;
    cin >> q;
    vector<int> changes(q);
    for (int& i : changes) cin >> i;

    int l=0,r=q-1;
    bool atleast1GoodSegmentFound = false;
    while (l < r) {
        int mid = (l+r) >> 1;
        
        bool theresGoodSegment = isThereGoodSegment(segments, n, mid, changes);
        if (theresGoodSegment){
            atleast1GoodSegmentFound = true;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (r == q-1) atleast1GoodSegmentFound = isThereGoodSegment(segments, n, r, changes);
    
    cout << (atleast1GoodSegmentFound ? r + 1 : -1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}
