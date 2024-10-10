#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0; i < n; i++){
            int j;
            cin >> j;
            q.push(j);
            while (q.front()<q.size())q.pop();
            cout << q.size() << ' ';
        }
        cout << '\n';
    }
}