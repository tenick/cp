#include <iostream>
#include <vector>
#include <algorithm>

// int numUniqueEmails(std::vector<std::string>& emails) {
    
// }

int subarrayLCM(std::vector<int>& nums, int l) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        for (int j = 0; j < nums.size() - i; j++){
            int ans = nums[0];
            
            for (int k = 0; k <= i; k++){
                ans = (((nums[k] * ans)) /
                        (std::__gcd(nums[k], ans)));
            }
            
            if (ans == l)
                count++;
        }
    }
    return count;   
}

int main(){
    int a = std::__gcd(6, 6);
    std::cout << a;
}