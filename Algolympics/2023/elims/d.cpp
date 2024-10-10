#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_set<char> possibleOps {'+', '-', '*', '/'};
vector<int> possibleDigits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
map<char, int> output;
vector<int> currComb;
bool found = false;
string equation;
string resultingEquation;
string outputInc;
string equationOutput;
char operation;
int operationPos;
int equalPos;
vector<char> chars;
unordered_map<char, vector<int>> charsByExprIndex;

void nCk(int k, int i){
    if (currComb.size() == k){
        // permute currComb here
        vector<int> currCombCopy = currComb;

        do {
            string rawOut = "";
            for (int j = 0; j < currCombCopy.size(); j++){
                rawOut.push_back(currCombCopy[j]);
                output[chars[j]] = currCombCopy[j];
                for (int ind : charsByExprIndex[chars[j]]){
                    resultingEquation[ind] = '0' + currCombCopy[j];
                }
            }

            // convert string expression to integer
            int op1 = stoi(resultingEquation.substr(0, operationPos));
            int op2 = stoi(resultingEquation.substr(operationPos+1, equalPos - operationPos - 1));
            int ans = stoi(resultingEquation.substr(equalPos+1, resultingEquation.size() - equalPos - 1));
            
            // test if it's correct
            int ans2;
            switch(operation){
                case '+':
                    ans2 = op1 + op2;
                    break;
                case '-':
                    ans2 = op1 - op2;
                    break;
                case '*':
                    ans2 = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) ans2 = -1;
                    else ans2 = op1 + op2;
                    break;
            }
            //cout << resultingEquation << '\n';
            if (ans == ans2 && op1 > 0 && op2 > 0 && ans > 0){
                if (!found){
                    outputInc = rawOut;
                    equationOutput = resultingEquation;
                    found = true;
                }
                if (rawOut.compare(outputInc) < 0){
                    outputInc = rawOut;
                    equationOutput = resultingEquation;
                }
            }
        }
        while (next_permutation(currCombCopy.begin(), currCombCopy.end()));
        return;
    }

    for (int j = i; j <= possibleDigits.size() - (k - currComb.size()); j++){
        currComb.push_back(possibleDigits[j]);
        nCk(k, j+1);
        currComb.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("out.txt","w",stdout);

    int t;
    cin >> t;
    
    while (t--){
        int c;
        cin >> c;
        cin >> equation;
        resultingEquation = equation;
        chars.clear();
        charsByExprIndex.clear();
        output.clear();
        currComb.clear();
        found = false;

        for (int i = 0; i < equation.size(); i++){
            if (possibleOps.find(equation[i]) != possibleOps.end()){
                operation = equation[i];
                operationPos = i;
            }
            else if (equation[i] == '=')
                equalPos = i;
            else{
                if (charsByExprIndex.find(equation[i]) == charsByExprIndex.end()){
                    charsByExprIndex[equation[i]] = vector<int>();
                    chars.push_back(equation[i]);
                    output[equation[i]] = 0;
                }
                charsByExprIndex[equation[i]].push_back(i);
            }
        }

        sort(chars.begin(), chars.end());


        // cout << equation << " | " << resultingEquation << '\n';
        // cout << operation << " | " << operationPos << " | " << equalPos << '\n';
        // cout << "chars: ";
        // for (char cc : chars) cout << cc << " ";
        // cout << '\n';
        // cout << "chars by expr index: \n";
        // for (auto& cc : charsByExprIndex){
        //     cout << cc.first << ": ";
        //     for (int i : cc.second){
        //         cout << i << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';


        nCk(c, 0);

        // for (auto& out : output){
        //     cout << out.first << " " << out.second << '\n';
        // }

        vector<bool> seen(10);
        for (int i = 0; i < equationOutput.size(); i++){
            char cc = equationOutput[i];
            int pos = cc - '0';
            if (pos >= 0 && pos < 10 && !seen[pos]){
                seen[pos] = true;
                output[equation[i]] = pos;
            }
        } 

        for (auto& ans : output){
            cout << ans.first << " " << ans.second << '\n';
        }

        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    }
}