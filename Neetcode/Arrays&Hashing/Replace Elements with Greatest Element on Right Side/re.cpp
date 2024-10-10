#include <iostream>
#include <vector>

std::vector<int> replaceElements(std::vector<int>& arr) {
    int maxn = -1;

    for (int i = arr.size() - 1; i >= 0; i--){
        int temp = arr[i];
        arr[i] = maxn;
        maxn = std::max(temp, maxn);
    }
    
    return arr;
}

int main() {
    std::vector<int> test1 { 17,18,5,4,6,1 };
    replaceElements(test1);
    std::cout << test1.size() << "wat\n";
    for (int i : test1){
        std::cout << i << '\n';
    }
    
}
