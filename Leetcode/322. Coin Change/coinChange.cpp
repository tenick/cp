#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef unsigned int ui;

int coinChange(vector<int>& coins, int amount, unordered_map<int, int>* memo = new unordered_map<int, int>) {
	if (memo->find(amount) != memo->end())
		return (*memo)[amount];
	if (amount < 0)
		return -1;
	if (amount == 0)
		return 0;
	int smallest = -1;
	for (int coin : coins){
		int result = coinChange(coins, amount-coin, memo);
		if (result != -1){
			if (smallest != -1){
				if (result + 1 < smallest)
					smallest = result + 1;
			}
			else
				smallest = result + 1;
		}
	}
	(*memo)[amount] = smallest;
	return smallest;
}

int main(int argc, char* argv[]){
	ui n = stoi(argv[1]);
	vector<int> coins = {1, 2, 5};
	//vector<int> coins = {2};
	//vector<int> coins = {1};
	
	int best = coinChange(coins, n);
	cout << best << "\n";
	return 0;
}