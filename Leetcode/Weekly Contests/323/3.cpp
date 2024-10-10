#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Allocator {
    vector<int> allocSize;
    unordered_map<int, vector<int>> mIDByIndices;
public:
    Allocator(int n) :  allocSize(n, 0) { }

    int allocate(int size, int mID){
        for (int i = 0; i < allocSize.size(); i++){
            if (allocSize[i] == 0){
                // check if can allocate
                bool canAlloc = true;
                int indexBlock = 0;
                
                if (i+size > allocSize.size())
                    break;
                
                for (int j = 0; j < size; j++){
                    if (allocSize[i + j] != 0){
                        canAlloc = false;
                        indexBlock = i + j;
                        break;
                    }
                }
                if (canAlloc){
                    allocSize[i] = size;
                    if (mIDByIndices.find(mID) == mIDByIndices.end())
                        mIDByIndices[mID] = {};
                    mIDByIndices[mID].push_back(i);
                    return i;
                }
                i = indexBlock - 1;
            }
            else
                i += allocSize[i] - 1;
                
        }
        return -1;
    }

    int free(int mID){
        auto index = mIDByIndices.find(mID);
        if (mIDByIndices.find(mID) != mIDByIndices.end()){
            int freeSize = 0;
            for (auto i : mIDByIndices[mID]){
                freeSize += allocSize[i];
                allocSize[i] = 0;
            }
            mIDByIndices.erase(mID);
            return freeSize;
        }
        return 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


}