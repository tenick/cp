#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> precomp(30);
    precomp[0] = 1;
    int sum = 0;
    for (int i = 1; i < 30; i++)
        precomp[i] = precomp[i-1] * 2;

    int t;
    cin >> t;

    while (t--){
        int cnt;
        cin >> cnt;

        int ignored1s = 0;
        int origN = 0;
        int i = 0;
        int prevCnt = cnt;
        while (cnt != ignored1s){
            cout << "- " << precomp[i] << '\n';
            fflush(stdout);
            cin >> cnt;

            if (cnt >= prevCnt){
                int toAdd = (cnt - prevCnt) + 1;
                i += toAdd;
                origN += precomp[i];
                ignored1s += toAdd;
            }
            else origN += precomp[i];

            prevCnt = cnt;
            i++;
        }
        cout << "! " << origN << '\n';
    }
}