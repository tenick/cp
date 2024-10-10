#include <iostream>
#include <vector>

using namespace std;

int pivotInteger(int n){
    vector<int> sums(n, 0);
    
    // first pass
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += i + 1;
        sums[i] = sum;
    }

    // second pass
    sum = 0;
    for (int i = n - 1; i >= 0; i--){
        sum += i + 1;
        if (sum == sums[i]) return i + 1;
    }
    return -1;
}

int main(){
    int n = 8;
    int pi = pivotInteger(n);
    cout << pi << endl;
}