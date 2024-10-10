#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int oddC = 0;
        int evenC = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] % 2) oddC++;
            else evenC++;
        }
        bool exists = (oddC > 0 && oddC < 3 && evenC > 1 ) || oddC >= 3;
        vector<int> indices(3);
        int i = 0;
        if (exists){
            cout << "YES\n";

            if (oddC >= 3){
                int count = 0;
                for (int i = 0; i < n; i++){
                    if (count == 3) break;
                    if (a[i] % 2 == 1){
                        cout << i+1 << " ";
                        count++;
                    }
                }
            }
            else {
                int odds = 0;
                int evens = 0;
                for (int i = 0; i < n; i++){
                    if (odds + evens == 3) break;
                    if (a[i] % 2 == 1){
                        if (odds == 1) continue;
                        cout << i+1 << " ";
                        odds++;
                    }
                    else {
                        if (evens == 2)
                            continue;
                        cout << i+1 << " ";
                        evens++;
                    }
                }
            }
            cout << '\n';
        }
        else cout << "NO\n";
    }
}