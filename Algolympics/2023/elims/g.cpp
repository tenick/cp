#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_set>

using namespace std;
const int SV = 5 * 1e6;
int numCount[SV + 1];
int redundancy[SV + 1];
bool seen[SV + 1];
unordered_set<int> sieved;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    memset(numCount, 0, sizeof numCount);
    memset(redundancy, 0, sizeof redundancy);
    memset(seen, 0, sizeof seen);
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        numCount[nums[i]]++;
    }

    for (int num : nums){
        if (seen[num]) continue;
        for (int i = num * 2; i <= SV; i += num){
            redundancy[i] += numCount[num];
        }
        seen[num] = true;
    }

    for (int num : nums){
        cout << redundancy[num] + numCount[num] - 1 << " ";
    }
    cout << '\n';
}
