#include <bits/stdc++.h>
typedef long long ll;

int main()
{
	int t;
	std::cin >> t;
	ll y, x;
	while (t--){
		std::cin >> y >> x;
		
		ll mx = std::max(y, x);
		if (mx % 2 == 1) { // if odd mx
			if (y == mx) 
				std::cout << (mx - 1) * (mx - 1) + x << "\n";
			else 
				std::cout << mx * mx - (y - 1) << "\n";
		}
		else { // if even mx
			if (x == mx) 
				std::cout << (mx - 1) * (mx - 1) + y << "\n";
			else 
				std::cout << mx * mx - (x - 1) << "\n";
		}
	}
    return 0;
}
