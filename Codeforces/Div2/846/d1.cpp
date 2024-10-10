#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int getCnt(int n){
    string s = bitset<30>(n).to_string(); // string conversion
    int cnt = 0;
    for (char c : s) cnt += c == '1';
    return cnt;
}

int main(){
    vector<int> precomp(30);
    precomp[0] = 1;
    int sum = 0;
    for (int i = 1; i < 30; i++)
        precomp[i] = precomp[i-1] * 2;

    int t;
    cin >> t;

    while (t--){
        int n = 939507712;
        //n = 536846336;

        int cnt = getCnt(n);
        cout << "n: " << n << " | " << bitset<30>(n).to_string() << " | currCnt: " << cnt << '\n';

        int ignored1s = 0;
        int origN = 0;
        int i = 0;
        int prevCnt = cnt;
        while (cnt != ignored1s){
            n -= precomp[i];
            cout << "n: " << n  << " | " << bitset<30>(n).to_string() << " | ignored1s: " << ignored1s << " | prevCnt: " << prevCnt << " | currCnt: " << getCnt(n) << '\n';
            cout << "- " << precomp[i] << " | " << bitset<30>(precomp[i]).to_string() << '\n';
            fflush(stdout);
            cin >> cnt;

            if (cnt >= prevCnt){
                int toAdd = (cnt - prevCnt) + 1;
                i += toAdd;
                origN += precomp[i];
                ignored1s += toAdd;
            }
            else origN += precomp[i];

            cout << "i: " << i << " | curr origN: " << origN << '\n';
            prevCnt = cnt;
            i++;
        }
        cout << "! " << origN << '\n';
    }
}