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
            int curr = ints[i];
            int l=max(0, i - curr + 1), r=i;
            while (l < r){
                int mid = (l+r)>>1;
                int range = i - mid + 1;
                if (ints[mid] >= range) r = mid;
                else l = mid+1;
            }
            cout << i - r + 1 << " ";
        }
        cout << '\n';
    }
}