#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while (t--){
        float d,w,b;
        cin >> d >> w >> b;
        if (ceil(d/w)-1 <= b)
            cout << "YES\n";
        else cout << "NO\n"; 
    }
}
