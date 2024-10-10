#include <bits/stdc++.h>

using namespace std;

int N, M;
string A, B;

int try_solve(int i, int j, int num_allow){
    if(i == N && j == M){
        return 1;
    }

    if(i == N){
        int m_rem = M - j;
        if (num_allow >= m_rem){
            return 1;
        } else {
            return 0;
        }
    }

    if(j == M){
        int n_rem = N - i;
        if (num_allow >= n_rem){
            return 1;
        } else {
            return 0;
        }
    }

    int ans = 0;

    if(A[i] == B[j]){
        int match_ret = try_solve(i+1, j+1, num_allow);
        ans |= match_ret;
    }

    if(num_allow && A[i] != B[j]){
        // Match the characters
        int change_ret = try_solve(i+1, j+1, num_allow-1);
        ans |= change_ret;

        // Delete from A
        int del_a = try_solve(i+1, j, num_allow-1);
        ans |= del_a;

        // Delete from B
        int del_b = try_solve(i, j+1, num_allow-1);
        ans |= del_b;
    }

    return ans;
}

int main(){
    string line;
    int cases;
    getline(cin, line);
    cases = stoi(line);

    for(int e = 0; e<cases; e++){
        getline(cin, A);
        getline(cin, B);
        N = A.size();
        M = B.size();

        if(try_solve(0, 0, 0)){
            cout << "You're logged in!" << endl;
        } else if (try_solve(0, 0, 1)){
            cout << "You almost got it. You're wrong in just one spot." << endl;
        } else if (try_solve(0, 0, 2)){
            cout << "You almost got it, but you're wrong in two spots." << endl;
        } else if (try_solve(0, 0, 3)){
            cout << "You're wrong in three spots." << endl;
        } else {
            cout << "What you entered is too different from the real password." << endl;
        }
    }


    return 0;
}