#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	
	float payment, vatSales,change, vatAmount, tp, temp, tempTotal, totalAmount = 0;
	int order, quantity, totalOrder = 0;
	char alaCarte, again;
	
	string items[5];
	float prices[5];
	for (int i = 0; i < 5; i++){
	    cout<<"Enter item " << (i+1) << ": ";
    	cin >> items[i];
    	cout<<"Enter the price of item item " << (i+1) << ": ";
    	cin >> prices[i];
	}
	
	cout<<"Generating menu...\n";
	//sleep(3);
	//system("cls");
	
	cout<<fixed<<setprecision(2);
	cout<<"********************************************"<<endl;
	cout<<"BURGERAN NI NICO"<<endl;
	cout<<"********************************************"<<endl;
	for (int i = 0; i < 5; i++){
	    cout<<(i+1)<<". "<<items[i]<<setw(30 - items[i].length())<<prices[i]<<endl;
	}
	
	cout<<"********************************************"<<endl;
	
	a:
	cout<<"Enter the number of your order: ";
	cin>>order;
	
	if (order < 1 || order > 5){
		cout<<"Invalid Order! Please try again!"<<endl;
		goto a;
	}
	tp = prices[order-1];
	cout<<"You have ordered "<<items[order-1]<<" priced at "<<prices[order-1]<<"."<<endl;
	
	
	cout<<"Would you like an ala carte order? Y/N: ";
	cin>>alaCarte;
		
	if (alaCarte == 'Y' || alaCarte == 'y'){
		temp = tp * 0.80;
		cout<<"How many would you like to order: ";
		cin>>quantity;
		tempTotal = temp * quantity;
	}
	else{
		cout<<"How many would you like to order: ";
		cin>>quantity;
		tempTotal = tp * quantity;
	}
	totalOrder = totalOrder + quantity;
	totalAmount = tempTotal + totalAmount;
	cout<<"Would you like to order another item? Y/N: ";
	cin>>again;
	
	if (again == 'Y' || again == 'y'){
		goto a;
	}
	
	cout<<"BILL: "<<totalAmount<<endl;
	cout<<"ORDER QUANTITY: "<<totalOrder;
	
	//sleep(3);
	//system("cls");
	cout<<"\n********************************************"<<endl;
	cout<<"BURGERAN NI NICO PAYMENT"<<endl;
	cout<<"********************************************"<<endl;
    b:
	cout<<"ENTER PAYMENT AMOUNT: ";
	cin>>payment;
	
    if (payment < totalAmount){
        cout << "Payment must be at least " << totalAmount << '\n';
        goto b;
    }

	cout<<"Generating reciept...";
	//sleep(3);
	//system("cls");
	
	vatSales = totalAmount / 1.12;
	vatAmount = totalAmount - vatSales;
	change = payment - totalAmount;
	cout<<"********************************************"<<endl;
	cout<<"BURGERAN NI NICO RECIEPT"<<endl;
	cout<<"********************************************"<<endl;
	cout<<"TOTAL NUMBER OF ITEMS ORDERED "<<setw(7)<<totalOrder<<endl;
	cout<<"VAT SALES"<<setw(32)<<vatSales<<endl;
	cout<<"VAT AMOUNT"<<setw(30)<<vatAmount<<endl;
	cout<<"ORDER TOTAL"<<setw(30)<<totalAmount<<endl;
	cout<<"AMOUNT TENDERED"<<setw(26)<<payment<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - "<<endl;
	cout<<"CHANGE"<<setw(34)<<change<<endl;
	
	return 0;
}
