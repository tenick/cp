#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    string a, b;
    cin >> a >> b;

    vector<string> pairs;
    string curr;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == b[i]){
            curr.push_back(a[i]);
        }
        else {
            if (curr != ""){
                pairs.push_back(curr);
                curr = "";
            }
        }
    }
    if (curr != ""){
        pairs.push_back(curr);
    }

    // for (auto pair : pairs){
    //     cout << pair.first << ", " << pair.second << '\n';
    // }
    // cout << "-------------------\n";

    if (pairs.size() == 1){
        cout << "YES\n";
    }
    else {
        auto front = pairs[0];
        auto back = pairs.back();
        pairs.erase(pairs.begin());
        pairs.erase(pairs.end()-1);

        bool fHas0 = front.find('0') != string::npos;
        bool fHas1 = front.find('1') != string::npos;
        bool bHas0 = back.find('0') != string::npos;
        bool bHas1 = back.find('1') != string::npos;


        if ((fHas0 && bHas0) || (fHas1 && bHas1)){
            cout << "YES\n";
        }
        else {

            vector<string> toFinds;
            if (fHas0 && bHas0)
                toFinds.push_back("00");
            if (fHas0 && bHas1)
                toFinds.push_back("01");
            if (fHas1 && bHas0)
                toFinds.push_back("10");
            if (fHas1 && bHas1)
                toFinds.push_back("11");

            // for (string tofind : toFinds){
            //     cout << tofind << " ";
            // }
            // cout << '\n';
            

            bool found = false;
            for (auto& pair : pairs){
                //cout << "curr pair: " << pair << '\n';

                for (string& toFind : toFinds){
                    int curr = 0;
                    for (char c : pair){
                        if (curr == 2){
                            found = true;
                            break;
                        }
                        if (c == toFind[curr]){
                            curr++;
                        }
                    }
                    if (curr == 2){
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (found){
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}