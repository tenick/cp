#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> dupls;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] >= 1){
            int currN = nums[i] - 1;
            nums[i] = 0;
            while (true) {
                if (nums[currN] == 0){
                    nums[currN] = -1;
                    break;
                }
                else if (nums[currN] == -1){
                    dupls.push_back(currN + 1);
                    break;
                }
                int temp = nums[currN];
                nums[currN] = -1;
                currN = temp - 1;
            }
        }
    }
    return dupls;
}

int main(){
    vector<int> nums {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> dupls = findDuplicates(nums);

    for (int i : dupls){
        cout << i << ',';
    }
}