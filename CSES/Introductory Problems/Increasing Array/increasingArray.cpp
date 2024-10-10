#include <bits/stdc++.h>
typedef long long int ll;
int main()
{
	int n;
	ll steps = 0;
	ll prevElement;
	ll element;
	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::cin >> element;
		if (i > 0) {
			if (element - prevElement < 0) {
				steps += (prevElement - element);
				continue;
			}
		}
		prevElement = element;
	}
	std::cout << steps;
    return 0;
}
