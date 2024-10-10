// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_perm(vector<int>::iterator s, vector<int>::iterator e){
    if (e - s == 0) return false;
    
    auto eT = e - 1;
    auto found = e;
    
    while (eT > s){
        auto curr = eT - 1;
        if (*curr < *eT){
            found = curr;
            break;
        }
        --eT;
    }
    if (found == e){
        cout << "from: " << (s - s) << " to: " << (e - s);
        reverse(s, e);
        return false;
    }
    
    auto eT2 = e - 1;
    while (true){
        if (*eT2 > *found){
            cout << " swapping " << (eT2 - s) << " and " << (found - s) << " ";
            iter_swap(eT2, found);
            break;
        }
        --eT2;
    }
    
    cout << "from: " << (eT - s) << " to: " << (e - s);
    reverse(eT, e);
    
    return true;
}

void nextPermutation(vector<int>& nums) {
    do {
        cout << '\n';
        for (int i : nums) cout << i << " ";
    }
    while(next_perm(nums.begin(), nums.end()));
}

int main() {
    vector<int> nums {1, 2, 3, 4, 5};
    nextPermutation(nums);

    return 0;
}