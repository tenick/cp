#include <iostream>

using namespace std;

int fb(int k, int b){
    if (k < b)
        return k;
    
    int ds = 0;
    while (k >= b){
        ds += k % b;
        k /= b;
    }
    
    return fb(ds + k, b);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int k, b;
        cin >> k >> b;

        for (int i = 0; i < b; i++){
            cout << fb(k * i, b) << " ";
        }
    }
}