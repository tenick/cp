#include <iostream>
#include <array>
#include <string>

int largest(int arr[], int n) 
{ 
    int i; 
    int max = arr[0]; 
    for (i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    return max; 
} 

int main()
{
    int t;
	scanf("%d", &t);
	while(t--){
		int n;
		int unsureCount = 0;
		std::string output = "";
		std::string addZero = "0 ";
		bool canBeZero = false;
		
		scanf("%d", &n);
		int* votes = (int*)calloc(n+1, sizeof(int));
		
		// getting votes
		for (int i = 0; i < n; i++){
			int vote;
			scanf("%d", &vote);
			if (vote == -1)
				unsureCount += 1;
			else
				votes[vote] += 1;
		}
		
		int mostSureCount = largest(votes, n+1);
		
		// check if -1 max
		if (unsureCount > mostSureCount){
			for (int i = 0; i <= n; i++){
				printf("%d ", i);
			}
		}
		else{ // mostSureCount is equal or higher than unsureCount
			// getting answer
			for (int i = 0; i <= n; i++){
				if (votes[i] + unsureCount > mostSureCount){
					if (i == 0) // 1 time check (just for 0th index), focus on else
						canBeZero = true;
					else
						output += std::to_string(i) + " ";
				}
				else if (votes[i] + unsureCount == mostSureCount)
					canBeZero = true;
			}
			if (canBeZero)
				output = addZero + output;
			 printf("%s ", output.c_str());
		}
		printf("\n");
	}
    return 0;
}















