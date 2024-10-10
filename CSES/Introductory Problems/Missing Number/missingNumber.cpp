#include <bits/stdc++.h>
typedef long long ll;
int main()
{
    ll n;
	std::cin >> n;
	ll N[n-1];
	for (int i = 0; i < n-1; i++)
		std::cin >> N[i];
	
	ll sum = 0;
	ll missingNumber;
	for (int i = 0; i < n-1; i++)
		sum += N[i];
	
	missingNumber = (n * (n + 1) / 2) - sum;
	std::cout << missingNumber;
    return 0;
}
