#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
  
    
        unordered_map<int, int> foodByLikes;
        vector<int> foods(n);
        for (int i = 0; i < n; i++){
            cin >> foods[i];

            if (foodByLikes.find(foods[i]) == foodByLikes.end())
                foodByLikes[foods[i]] = 0;
            foodByLikes[foods[i]]++;
        }

        vector<int> majorityLikedFoods;
        for (auto kvp : foodByLikes){
            majorityLikedFoods.push_back(kvp.second);
        }
        sort(majorityLikedFoods.begin(), majorityLikedFoods.end(), greater<int>());


        vector<int> tables(m);
        for (int i = 0; i < m; i++){
            cin >> tables[i];
        }
        sort(tables.begin(), tables.end(), greater<int>());

        int maxSatisfied = 0;
        int i = 0;
        int j = 0;
        while (i < majorityLikedFoods.size() && j < m){
            int mostLiked = majorityLikedFoods[i];
            int tCapacity = tables[j];
            if (mostLiked > tCapacity){
                majorityLikedFoods[i] -= tCapacity;
                mostLiked = tCapacity;
                i--;
            }
            maxSatisfied += min(mostLiked, tCapacity);
            i++; j++;
        }

        cout << maxSatisfied << '\n';
    }
}