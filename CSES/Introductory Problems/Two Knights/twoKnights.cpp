#include <bits/stdc++.h>
typedef long long ll;
ll NCR(int n, int r);


int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == 0){
			std::cout << "0\n";
			continue;
		}

		int n = i + 1;
		int sqr = n*n;
		ll totalCombinations = NCR(sqr, 2);
		ll totalRestrictedSquares = ((n-1)*(n-2))*4;
		totalCombinations -= totalRestrictedSquares;
		std::cout << totalCombinations << "\n";
	}
    return 0;
}

ll NCR(int n, int r)
{
    if (r == 0) return 1;

    /*
     Extra computation saving for large R,
     using property:
     N choose R = N choose (N-R)
    */
    if (r > n / 2) return NCR(n, n - r); 

    ll res = 1; 

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}
