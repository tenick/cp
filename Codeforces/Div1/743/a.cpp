#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Chapter {
public:
    int chapter;
    vector<Chapter*> relatedChaps;
    bool cycleCheck = false;
    bool stacked = false;
    unordered_set<int> reqChapsRead;
    int reqChapsCount=0;
    void AddReqChap(Chapter* chap){
        relatedChaps.push_back(chap);
    }
};

bool isCyclic(Chapter* chap){
    if (chap->cycleCheck){
        return true;
    }
    else chap->cycleCheck = true;

    for (auto i : chap->relatedChaps){
        if (isCyclic(i)) return true;
    }
    chap->cycleCheck = false;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;

        vector<Chapter*> chapters(n, nullptr);
        for (int i = 0; i < n; i++){
            chapters[i] = new Chapter;
            chapters[i]->chapter = i + 1;
        }

        int totalChaptersRead = 0;
        int totalBookRead = 1;
        stack<Chapter*> s;
        stack<Chapter*> ns;

        for (int i = 0; i < n; i++){
            int k;
            cin >> k;
            
            if (k == 0) s.push(chapters[i]);
            for (int j = 0; j < k; j++){
                int ch;
                cin >> ch;
                chapters[ch - 1]->relatedChaps.push_back(chapters[i]);
            }
            chapters[i]->reqChapsCount = k;
        }


        // check for cycles first
        stack<Chapter*> c = s;
        bool isCycle = false;
        while (!c.empty()){
            Chapter* chap = c.top();
            c.pop();
            if (isCyclic(chap)){
                isCycle = true;
                break;
            }
        }

        if (isCycle){
            cout << "-1\n";
            for (auto it = chapters.begin(); it != chapters.end(); it++){
                delete *it;
            }
            continue;
        }

        while (!s.empty()){
            Chapter* currChap = s.top();
            s.pop();

            if (currChap->reqChapsRead.size() == currChap->reqChapsCount) totalChaptersRead++;

            for (auto i : currChap->relatedChaps){
                i->reqChapsRead.insert(currChap->chapter);
                if (i->chapter > currChap->chapter) s.push(i);
                else if (i->reqChapsRead.size() == i->reqChapsCount) ns.push(i);
            }

            if (s.empty() && !ns.empty()){
                totalBookRead++;
                s = ns;
                ns = stack<Chapter*>();
            }
        }

        cout << (totalChaptersRead >= n ? totalBookRead : -1) << '\n';

        for (auto it = chapters.begin(); it != chapters.end(); it++){
            delete *it;
        }
    }
}