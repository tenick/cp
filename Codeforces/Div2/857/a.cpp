#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> likes(n);
    for (int i = 0; i < n; i++) cin >> likes[i];
    

    sort(likes.rbegin(), likes.rend());
    int maxLikes = 0;
    for (int i = 0; i < n; i++){
        if (likes[i] > 0)
            maxLikes++;
        else 
            maxLikes--;
        cout << maxLikes << " ";
    }
    cout << '\n';

    sort(likes.begin(), likes.end());
    int negs = 0;
    maxLikes = 0;
    for (int i = 0; i < n; i++){
        if (likes[i] < 0) negs++;
        else {
            maxLikes++;
            cout << maxLikes << " ";
            if (negs > 0) {
                cout << --maxLikes << " ";
                negs--;
            }
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}