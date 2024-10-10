#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int sum = 0;
        int minnsz = 2;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        for (int i = 0; i < n; i++){
            sum += nums[i];
            if (i > 0)
                minnsz = min(minnsz, nums[i] + nums[i-1]);
        }

        cout << sum + minnsz * -2 << '\n';
    }
}