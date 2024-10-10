#include <bits/stdc++.h>

using namespace std;

int main(){
    int age;
    string str;

    cin >> age >> str;

    if(str == "G"){
        cout << "OK" << endl;
    } else if(str == "PG") {
        if(age < 13){
            cout << "OK IF ACCOMPANIED" << endl;
        } else {
            cout << "OK" << endl;
        }
    } else if (str == "R-13" && age >= 13){
        cout << "OK" << endl;
    } else if (str == "R-16" && age >= 16){
        cout << "OK" << endl;
    } else if (str == "R-18" && age >= 18){
        cout << "OK" << endl;
    } else {
        cout << "ACCESS DENIED" << endl;
    }

    return 0;
}