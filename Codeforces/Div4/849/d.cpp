#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        int n;
        string s;
        cin >> n >> s;

        set<char> set1;
        set<char> set2;
        vector<int> lSum(n);
        vector<int> rSum(n);
        int total = 0;
        for (int i = 0; i < n; i++){
            char c = s[i];
            if (set1.find(c) == set1.end())
                set1.insert(c);

            lSum[i] = set1.size();
        }

        for (int i = n-1; i >= 0; i--){
            char c = s[i];
            if (set2.find(c) == set2.end())
                set2.insert(c);

            rSum[i] = set2.size();
        }

        for (int i = 1; i < n; i++){
            total = max(total, lSum[i-1] + rSum[i]);
        }

        cout << total << '\n';
    }
}