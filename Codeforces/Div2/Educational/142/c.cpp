#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<int> inds(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            inds[nums[i]-1] = i;
        }
        
        int l=n/2, r=l;
        l--;
        if (n%2==1)r++;
        int swaps = 0;
        bool swappedLeft = false;
        bool swappedRight = false;
        while (l >= 0){
            if (!swappedRight && inds[r-1] > inds[r])
                swappedRight = true;
            if (!swappedLeft && inds[l+1] < inds[l])
                swappedLeft = true;
            swaps += swappedLeft || swappedRight;
            l--;r++;
        }
        cout << swaps << '\n';
    }
}