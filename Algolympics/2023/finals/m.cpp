#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solve(){
    int n, r;
    cin >> n >> r;
    vector<int> orgInds;
    vector<string> orgs;
    for (int i = 0; i < n; i++){
        string org;
        cin >> org;
        orgs.push_back(org);
        orgInds.push_back(i+1);
    }

    cout << "curr orgInds: ";
    for (int z : orgInds) cout << z << ' ';
    cout << '\n';
    cout << "curr orgs: ";
    for (string z : orgs) cout << z << ' ';
    cout << '\n';

    vector<map<string, set<string>>> personalRecs(3, map<string, set<string>>());
    for (int i = 0; i < r; i++){
        char p1;
        string x1, y1;
        cin >> p1 >> x1 >> y1;
        if (personalRecs[p1-'A'].find(x1) == personalRecs[p1-'A'].end()){
            personalRecs[p1-'A'][x1] = set<string>(); 
        }
        personalRecs[p1-'A'][x1].insert(y1);
        if (personalRecs[p1-'A'].find(y1) == personalRecs[p1-'A'].end()){
            personalRecs[p1-'A'][y1] = set<string>(); 
        }
        personalRecs[p1-'A'][y1].insert(x1);
    }
    
    vector<map<int, set<int>>> theBuzz(3, map<int, set<int>>());
    for (int i = 0; i < r; i++){
        char p1;
        int x1, y1;
        cin >> p1 >> x1 >> y1;

        if (theBuzz[p1-'A'].find(x1) == theBuzz[p1-'A'].end()){
            theBuzz[p1-'A'][x1] = set<int>(); 
        }
        theBuzz[p1-'A'][x1].insert(y1);
        if (theBuzz[p1-'A'].find(y1) == theBuzz[p1-'A'].end()){
            theBuzz[p1-'A'][y1] = set<int>(); 
        }
        theBuzz[p1-'A'][y1].insert(x1);
    }

    int possibleCount = 0;
    vector<int> assignation;

    do {
        cout << "curr perm: ";
        for (int z : orgInds) cout << z << ' ';
        cout << '\n';
        for (int j = 0; j < n; j++){
            int orgInd = orgInds[j];
            string org = orgs[j];

            bool consistent = true;
            cout << "org: " << org << " ind: "<< orgInd << '\n';
            for (int i = 0; i < 3; i++){
                auto& graphBuzz = theBuzz[i];
                auto& graphPersoRec = personalRecs[i];
                
                cout << (char)('A'+i) << ":\n";
                cout << "ind relations: \n";
                for (auto& kvp : graphBuzz){
                    cout << kvp.first << ": ";
                    for (int relati : kvp.second){
                        cout << relati << " ";
                    }
                }
                cout << '\n';
                
                cout << "org relations: \n";
                for (auto& kvp : graphPersoRec){
                    cout << kvp.first << ": ";
                    for (string relati : kvp.second){
                        cout << relati << " ";
                    }
                }
                cout << '\n';


                if ((graphBuzz.find(orgInd) == graphBuzz.end()) == (graphPersoRec.find(org) == graphPersoRec.end())){
                    cout << "teststst\n";
                    if (graphBuzz.find(orgInd) != graphBuzz.end()){
                        cout << "teststst2\n";
                        for (auto& relation : graphBuzz[orgInd]){
                            cout << relation << " ";
                            if (graphPersoRec[org].find(orgs[relation-1]) == graphPersoRec[org].end()){
                                cout << "inconsistent!\n";
                                consistent = false;
                                break;
                            }
                        }
                    }
                }
                else {
                    consistent = false;
                }
                
                
                cout << '\n';

                if (!consistent) break;
            }

            if (!consistent) break;
            else {
                possibleCount++;
                assignation = orgInds;
            }
        }
    }
    while(next_permutation(orgInds.begin(), orgInds.end()));

    if (possibleCount == 0){
        cout << "IMPOSSIBLE\n";
    }
    else if (possibleCount == 1){
        for (int assig : assignation) cout << orgs[assig-1] << '\n';
    }
    else {
        cout << "TOO MANY\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    while (t--){
        solve();
    }
}