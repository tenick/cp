#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

std::vector<int> sieveOfEratosthenes(int n){
	std::vector<int> primesVec;
	// initializing sieve
    int* primes = (int*)calloc((n+1), sizeof(int));
    // sieve of eratosthenes	
    for(int i = 3; i <= (int)std::floor(std::sqrt(n)); i+=2)
        if(*(primes+(i-2)) == 0)			
            for(int j = i; i*j<=n; j++)
                *(primes+((i*j)-2)) = 1;
    // pushing all primes to vector
	primesVec.push_back(2);
    for(int i = 3; i <= n; i+=2)
        if (*(primes+(i-2)) == 0)
            primesVec.push_back(i);
	// Deallocating memory
	free(primes);
	
	return primesVec;
}

void segmentedSieve(int m, int n){
	bool* primes = (bool*)calloc((n-m+1), sizeof(bool));
	if (m == 1)
		primes[0] = 1;
	std::vector<int> primesToConsider = sieveOfEratosthenes(std::floor(std::sqrt(n)));
	for (int i : primesToConsider){
		for (int j = m + (i - m%i) * (bool)(m%i); j <= n; j+=i){
			if (j == i)
				continue;
			primes[j-m] = 1;
		}
	}
	for (int i = m; i <= n; i++)
		if (primes[i-m] == 0)
			printf("%d\n", i);
	free(primes);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int m;
		int n;
        scanf("%d%d", &m, &n);
        segmentedSieve(m, n);
    }
    return 0;
}
