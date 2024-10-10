#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& a, int t){
    int carvers = 0;
    int curr = a[0];
    for (int i = 0; i < a.size(); i++){
        if (a[i] - curr > 2*t){
            //cout << "not possible from " << curr << " to " << a[i] << '\n';
            carvers++;
            curr = a[i];
            i--;
            continue;
        }
    }
    return carvers <= 2;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    sort(a.begin(), a.end());


    int l=0,r=1e9;
    while (r > l){
        int mid = (l + r) >> 1;
        if (check(a, mid)){
            //cout << "ans: " << mid << " possible!" << '\n';
            r = mid;
        }
        else {
            //cout << "ans: " << mid << " not possible!" << '\n';
            l = mid+1;
        }
        //cout << "l=" << l << ", r=" << r << '\n'; 
    }
    cout << l << '\n';
    //cout << "----------\n\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}