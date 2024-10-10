#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int D, N;
    cin >> D >> N;

    vector<int> A(D);
    for (int i = 0; i < D; i++)
        cin >> A[i];
    vector<int> B(D);
    for (int i = 0; i < D; i++)
        cin >> B[i];
    vector<vector<int>> n(N, vector<int>(D));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < D; j++){
            cin >> n[i][j];
        }
    }

    for (auto& vec : n){
        bool sus = true;
        for (int i = 0; i < D; i++){
            if (!(vec[i] >= A[i] - B[i] && vec[i] <= A[i])){
                sus = false;
                break;
            }
        }
        if (sus) cout << "SUS\n";
        else cout << "INNOCENT\n"; 
    }
}