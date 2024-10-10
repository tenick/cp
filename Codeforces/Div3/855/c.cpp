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

        vector<int> deck(n);

        for (int i = 0; i < n; i++)
            cin >> deck[i];

        priority_queue<int> pq;
        long long maxPower = 0;
        
        for (int i = 0; i < n; i++){
            if (deck[i] > 0)
                pq.push(deck[i]);
            else if (!pq.empty()){
                maxPower += pq.top();
                pq.pop();
            }
        }

        cout << maxPower << '\n';
    }
}
