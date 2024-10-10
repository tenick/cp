#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

unordered_set<char> possibleOps {'+', '-', '*', '/'};

string eq;
char operation;
int op1DigitCount;
int op2DigitCount;
int resDigitCount;
int operationPos;
int equalPos;
int permInOrder=0,op1=0,op2=0,ans=0;
unordered_map<char, vector<int>> charsByTermsAdd;
vector<char> chars;

int currentPermOrder = 1e9;

bool next_perm(vector<int>::iterator s, vector<int>::iterator e){
    if (e - s == 0) return false;

    int resAns;
    switch(operation){
        case '+':
            resAns = op1 + op2;
            break;
        case '-':
            resAns = op1 - op2;
            break;
        case '*':
            resAns = op1 * op2;
            break;
        case '/':
            if (op2 == 0) resAns = -1;
            else resAns = op1 / op2;
            break;
    }

    if (ans == resAns && op1 > 0 && op2 > 0 && ans > 0){
        if (permInOrder < currentPermOrder)
            currentPermOrder = permInOrder;
        return false;
    }

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
        return false;
    }

    auto eT2 = e - 1;
    while (true){
        if (*eT2 > *found){
            int s1 = eT2 - s;
            int s2 = found - s;

            int nums1 = *eT2;
            int nums2 = *found;

            //cout << "swapping from " << s1 << " to: " << s2 << '\n';

            permInOrder -= nums1 * pow(10, (int)chars.size() - s1 - 1);
            permInOrder -= nums2 * pow(10, (int)chars.size() - s2 - 1);
            //cout << permInOrder << " to: ";

            char ch1 = chars[(int)s1];
            char ch2 = chars[(int)s2];
            op1 -= nums1 * charsByTermsAdd[ch1][0];
            op2 -= nums1 * charsByTermsAdd[ch1][1];
            ans -= nums1 * charsByTermsAdd[ch1][2];

            op1 -= nums2 * charsByTermsAdd[ch2][0];
            op2 -= nums2 * charsByTermsAdd[ch2][1];
            ans -= nums2 * charsByTermsAdd[ch2][2];

            iter_swap(eT2, found);

            nums1 = *eT2;
            nums2 = *found;

            permInOrder += nums1 * pow(10, (int)chars.size() - s1 - 1);
            permInOrder += nums2 * pow(10, (int)chars.size() - s2 - 1);

            op1 += nums1 * charsByTermsAdd[ch1][0];
            op2 += nums1 * charsByTermsAdd[ch1][1];
            ans += nums1 * charsByTermsAdd[ch1][2];

            op1 += nums2 * charsByTermsAdd[ch2][0];
            op2 += nums2 * charsByTermsAdd[ch2][1];
            ans += nums2 * charsByTermsAdd[ch2][2];
            //cout << permInOrder << "\n";
            break;
        }
        --eT2;
    }
    
    int l = eT - s;
    int r = e - s - 1;
    //cout << "reversing from: " << l << " to: " <<  r << "\n";
    while (l < r){
        int s1 = l;
        int s2 = r;

        auto ptrL = (s + l);
        auto ptrR = (s + r);

        int nums1 = *ptrL;
        int nums2 = *ptrR;

        //cout << "nums1: " << nums1 << " nums2: " << nums2 << '\n';

        permInOrder -= nums1 * pow(10, (int)chars.size() - s1 - 1);
        permInOrder -= nums2 * pow(10, (int)chars.size() - s2 - 1);

        char ch1 = chars[(int)s1];
        char ch2 = chars[(int)s2];
        op1 -= nums1 * charsByTermsAdd[ch1][0];
        op2 -= nums1 * charsByTermsAdd[ch1][1];
        ans -= nums1 * charsByTermsAdd[ch1][2];

        op1 -= nums2 * charsByTermsAdd[ch2][0];
        op2 -= nums2 * charsByTermsAdd[ch2][1];
        ans -= nums2 * charsByTermsAdd[ch2][2];

        iter_swap(ptrL, ptrR);

        nums1 = *ptrL;
        nums2 = *ptrR;

        permInOrder += nums1 * pow(10, (int)chars.size() - s1 - 1);
        permInOrder += nums2 * pow(10, (int)chars.size() - s2 - 1);

        op1 += nums1 * charsByTermsAdd[ch1][0];
        op2 += nums1 * charsByTermsAdd[ch1][1];
        ans += nums1 * charsByTermsAdd[ch1][2];

        op1 += nums2 * charsByTermsAdd[ch2][0];
        op2 += nums2 * charsByTermsAdd[ch2][1];
        ans += nums2 * charsByTermsAdd[ch2][2];

        l++;r--;
    }

    return true;
}

void nCk(int k, int i, vector<int>& currComb){
    if (currComb.size() == k){
        vector<int> currCombCopy = currComb;
        permInOrder=0,op1=0,op2=0,ans=0;
        
        for (int j = 0; j < k; j++){
            int num = currCombCopy[j];
            char ch = chars[j];

            permInOrder += num * pow(10, k - j - 1);

            op1 += num * charsByTermsAdd[ch][0];
            op2 += num * charsByTermsAdd[ch][1];
            ans += num * charsByTermsAdd[ch][2];
        }
        
        while (next_perm(currCombCopy.begin(), currCombCopy.end()));

        return;
    }

    for (int j = i; j <= 10 - (k - currComb.size()); j++){
        currComb.push_back(j);
        nCk(k, j+1, currComb);
        currComb.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int c;
        cin >> c;
        cin >> eq;

        charsByTermsAdd.clear();
        chars.clear();
        currentPermOrder = 1e9;

        for (int i = 0; i < eq.size(); i++){
            if (possibleOps.find(eq[i]) != possibleOps.end()){ // if operator char
                operation = eq[i];
                operationPos = i;
                op1DigitCount = i;
            }
            else if (eq[i] == '='){  // if equal sign char
                equalPos = i;
                op2DigitCount = i - operationPos - 1;
                resDigitCount = eq.size() - i - 1;
            }
            else{ // if letter
                if (charsByTermsAdd.find(eq[i]) == charsByTermsAdd.end()){
                    charsByTermsAdd[eq[i]] = vector<int>(3);
                    chars.push_back(eq[i]);
                }
            }
        }

        for (int i = 0; i < eq.size(); i++){
            if (i == operationPos || i == equalPos) continue;
            
            if (i < operationPos) // op1
                charsByTermsAdd[eq[i]][0] += pow(10, op1DigitCount - i - 1);
            else if (i < equalPos) // op2
                charsByTermsAdd[eq[i]][1] += pow(10, op2DigitCount - (i - (operationPos + 1)) - 1);
            else // ans
                charsByTermsAdd[eq[i]][2] += pow(10, resDigitCount - (i - (equalPos + 1)) - 1);
        }

        sort(chars.begin(), chars.end());

        vector<int> currComb;
        nCk(c, 0, currComb);


        vector<int> charVals(c);
        for (int i = c-1; i >= 0; i--){
            int currNum = currentPermOrder % 10;
            currentPermOrder /= 10;
            charVals[i] = currNum;
        }

        for (int i = 0; i < c; i++){
            cout << chars[i] << " " << charVals[i] << '\n';
        }
    }
}
