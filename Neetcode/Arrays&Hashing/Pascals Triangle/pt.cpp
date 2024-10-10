#include <iostream>
#include <vector>

#define MAX_ROW 30

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> pascalsTriangle{{1}};
    pascalsTriangle.reserve(MAX_ROW);

    if (numRows != 1) pascalsTriangle.push_back({1,1});

    for (int i = 3; i <= numRows; i++){
        std::vector<int> newRow;
        newRow.reserve(i);

        newRow.push_back(1);
        for (int j = 0; j < i - 2; j++)
            newRow.push_back(pascalsTriangle[i - 2][j] + pascalsTriangle[i - 2][j + 1]);
        newRow.push_back(1);

        pascalsTriangle.push_back(newRow);
    }

    return pascalsTriangle;
}

int main() {
    int numRows = 50;
    auto res = generate(numRows);

    for (std::vector<int> row : res){
        for (int i : row){
            std::cout << i << ',';
        }
        std::cout << '\n';
    }
}