#include <bits/stdc++.h>
using namespace std;
int main() {
    int age;
    string rating, title;
    cin >> age >> rating;
    cin.ignore();
    getline(cin, title);
    if (rating == "G") {
        cout << "OK";
    }
    else if (rating == "PG") {
        if (age < 13) cout << "OK IF ACCOMPANIED";
        else cout << "OK";
    }
    else {
        int lim = stoi(rating.substr(2, rating.size()));
        if (age < lim) cout << "ACCESS DENIED";
        else cout << "OK";
    }
    cout << endl;
    return 0;
}