#include <bits/stdc++.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        std::string expr;
        std::string RPN;
		std::stack<char> stack1;
		
		std::cin >> expr;
		
		for (char a : expr){
			if (a == ')'){
				RPN += stack1.top();
				stack1.pop();
			}
			else if (isalpha(a))
				RPN += a;
			else if (a != '(')
				stack1.push(a);
		}
        std::cout << RPN << "\n";
    }
    return 0;
}
