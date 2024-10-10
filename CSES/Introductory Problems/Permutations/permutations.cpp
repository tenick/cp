#include <bits/stdc++.h>

int main()
{
	int n;
	std::cin >> n;
	if (n == 1)
		std::cout << "1";
	else if (n > 1 && n < 4)
		std::cout << "NO SOLUTION";
	else if (n == 4)
		std::cout << "3 1 4 2";
	else if (n == 5)
		std::cout << "4 2 5 3 1";
	else { // for n > 5
		int count = 1;
		// print odds
		while (count <= n) {
			std::cout << count << " ";
			count += 2;
		}
		
		count = 2;
		// print evens
		while (count <= n) {
			std::cout << count << " ";
			count += 2;
		}
	}
    return 0;
}
