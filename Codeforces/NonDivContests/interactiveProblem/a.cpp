#include <iostream>
#include <string>

using namespace std;

int main(){
    int currP = 0;
    int l = 1;
    int r = 1e6;
    int wasLT = false;
    while (l <= r){
        currP = (r + l) / 2;
        cout << currP << '\n';
        fflush(stdout);

        string inp;
        cin >> inp;
        
        if (inp == "<"){
            wasLT = true;
            r = currP - 1;
        }
        else {
            wasLT = false;
            l = currP + 1;
        }
    }

    cout << "! ";
    if (wasLT)
        cout << currP - 1 << '\n';
    else cout << currP << '\n';
}