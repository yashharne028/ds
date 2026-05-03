/*
AIM: Write a C++ program 
to read numeric values from the user 
till the users explicitly stops the input. 
Perform addition on all these input numbers 
and print the result. 
(Do not use an array or any other data structure 
for storing these numbers. The numbers are read from user on fly).
Analyse the space and time complexity of the program.

INPUT: y/n as a choice and any numeric value
OUTPUT: Print sum of all input numbers
Author: Sunil Rathod
Date: 10.07.2025
*/
#include<iostream>
using namespace std;
class SumNNumbers{
	private:
	//Data
	int num, sum=0;
	char choice='y';
	
	public:
	//Member function
	void sumNNum(){
		while(choice == 'y'){
		cout<<"\nEnter any number::";
		cin>>num;
		sum=sum+num;
		cout<<"\nEnter your choice y/n::";
		cin>>choice;
		}
		cout<<"\nThe sum of numbers is::"<<sum;
	}
};

int main(){
	SumNNumbers obj;
	obj.sumNNum();

	return 0;
}