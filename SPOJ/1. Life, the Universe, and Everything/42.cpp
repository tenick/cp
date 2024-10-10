#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    while(x != 42){
        cin >> x;
        if(x == 42){
        	break;
        }
        cout << x << endl;
    }
    return 0;
} 