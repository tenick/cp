#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

float dist(float x1, float y1, float x2, float y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool isInCircle(float cx, float cy, float r, float x, float y) {
    return dist(cx, cy, x, y) <= r;
}
bool are2CirclesIntersecting(float cx1, float cy1, float r1, float cx2, float cy2, float r2){
    return dist(cx1, cy1, cx2, cy2) <= r1 + r2;
}

bool isPathtoHomeCompletelyIlluminated(float w, int px, int py, int ax, int ay, int bx, int by){
    // check if both O and P is included in lantern A
    if (isInCircle(ax, ay, w, px, py) && isInCircle(ax, ay, w, 0, 0))
        return true;

    // check if both O and P is included in lantern B
    if (isInCircle(bx, by, w, px, py) && isInCircle(bx, by, w, 0, 0))
        return true;

    // check if O and P is not in either A or B (reaching here means that they are not in the same lantern)
    if ((!isInCircle(ax, ay, w, px, py) && !isInCircle(bx, by, w, px, py)) || (!isInCircle(ax, ay, w, 0, 0) && !isInCircle(bx, by, w, 0, 0)))
        return false;
    
    // reaching here means that O and P are inside lantern A or B, but not in the same lantern
    // so finally, just check if the lanterns radius' are intersecting
    return are2CirclesIntersecting(ax, ay, w, bx, by, w);
}


void solve(){
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    float l=1,r=1e9;
    int minIter = 60;
    int curr = 0;
    while (true) {
        float w = (l + r) / 2;
        
        if (isPathtoHomeCompletelyIlluminated(w, px, py, ax, ay, bx, by))
            r = w;
        else
            l = w;
        if (++curr == minIter) break;
    }
    cout << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}