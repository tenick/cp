#include <iostream>
#include <algorithm>
#include <cmath>

void sieveOfEratosthenes(int n){
	// initializing sieve
    int* primes = (int*)calloc((n+1), sizeof(int));
    // sieve of eratosthenes	
    for(int i = 3; i <= (int)std::floor(std::sqrt(n)); i+=2)
        if(*(primes+(i-2)) == 0)			
            for(int j = i; i*j<=n; j++)
                *(primes+((i*j)-2)) = 1;
    // displaying
	printf("%d, ", 2);
    for(int i = 3; i <= n; i+=2)
        if (*(primes+(i-2)) == 0)
            printf("%d, ", i);
	printf("\n");
	// Deallocating memory
	free(primes);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        sieveOfEratosthenes(n);
    }
    return 0;
}
