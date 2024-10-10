#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        cout << ((a + b) % 3 == 0 && abs(a - b) <= min(a, b) ? "YES\n" : "NO\n");
    }
}