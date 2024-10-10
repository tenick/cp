#include <bits/stdc++.h>

int main()
{
    unsigned long input;
    std::cin >> input;
    while (input != 1){
        std::cout << input << ' ';
        if (input % 2 == 0) // even
            input /= 2;
        else // odd
            input = input * 3 + 1;
    }
    std::cout << input << ' ';
    return 0;
}
