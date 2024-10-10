#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> perms(n);
        vector<int> permsInd(n);
        for (int i = 0; i < n; i++){
            cin >> perms[i];
            permsInd[perms[i] - 1] = i + 1; 
        }

        vector<int> arr(m);
        vector<int> arrInds(m);
        //cout << "perms: " << n << " | d: " << d << " | ans: ";
        for (int i = 0; i < m; i++){
            cin >> arr[i];
            arrInds[i] = permsInd[arr[i] - 1];
            //cout << arrInds[i] << ' ';
        }

        bool isntGood = false;
        int nearest = n;
        for (int i = 0; i < m - 1; i++){
            if (!(arrInds[i] < arrInds[i+1] && arrInds[i] + d >= arrInds[i+1])){
                isntGood = true;
                break;
            }
            nearest = min(nearest, abs(arrInds[i] - arrInds[i+1]));
            
            int potential = d + 1 - abs(arrInds[i] - arrInds[i+1]);
            //cout << "potential " << potential << " at: arrInds[" << i << "] = " << arrInds[i] << '\n';
            if (arrInds[i+1] + potential <= n)
                nearest = min(nearest, potential);
            else {
                int rightMove = n - arrInds[i+1];
                int leftMove = arrInds[i] - 1;
                //cout << "move right: " << rightMove << " | " << " move left : " << leftMove << '\n';
                int possible =  rightMove + leftMove;
                if (possible >= potential) nearest = min(nearest, potential);
            }
        }

        int total = 0;
        if (isntGood) cout << total << '\n';
        else {
            cout << nearest << '\n';
        }
    }
}