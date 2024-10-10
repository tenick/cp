#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

double calcIsoTriangleArea(double y, double b, double h, double upto){
    double slope = h / (b/2);
    double x2 = upto/slope;
    double area = x2 * upto / 2;
    area += (b/2 - x2) * upto;
    return area*2;
}

void solve(){
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> yvals(n);
    for (int& i : yvals) cin >> i;
    sort(begin(yvals), end(yvals));

    double totalArea = 0;
    for(int i = 0; i < n; i++){
        double upto = h;
        if (i < n-1 && yvals[i+1] - yvals[i] < h){
            upto = yvals[i+1] - yvals[i];
        }

        totalArea += calcIsoTriangleArea(yvals[i], d, h, upto);
    }
    cout << totalArea << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(9);
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}