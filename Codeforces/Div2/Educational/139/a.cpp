#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;

        int count = min(9, n);

        while (true){
            int newN = n / 10;

            if (newN >= 10){
                count += 9;
                n = newN;
            }
            else {
                count += newN;
                break;
            }
        }

        cout << count << '\n';
    }
}