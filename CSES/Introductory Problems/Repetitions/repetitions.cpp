#include <bits/stdc++.h>

int main()
{
	int count = 0;
	int longest = 0;
	std::string str;
	std::cin >> str;
	char currentChar;
	for (int i = 0; i < str.size(); i++){
		if (currentChar != str[i]){
			currentChar = str[i];
			count = 0;
		}
		count += 1;
		if (count > longest)
			longest = count;
	}
	std::cout << longest;
    return 0;
}
