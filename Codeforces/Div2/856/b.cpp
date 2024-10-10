#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;
        vector<int> ints(n);
        for (int i = 0; i < n; i++)
            cin >> ints[i];

        for (int i = 0; i < n; i++){
            if (ints[i] == 1) ints[i]++;
        }

        cout << ints[0] << ' ';
        for (int i = 1; i < n; i++){
            if (ints[i] % ints[i-1] == 0)
                ints[i]++;
            cout << ints[i] << ' ';
        }
        cout << '\n';

    }
}