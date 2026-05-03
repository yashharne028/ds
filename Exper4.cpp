/*
AIM:
Write a C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers 
in ascending order using
a) Selection Sort
b) Bubble sort and 
c) display top five scores.

INPUT: Read Roll numbers of students
OUTPUT:
a) sort student using Bubble Sort
b) sort student using Selection sort
c) Display top five scores

Author: Sunil Rathod
Date: 11.08.2025
*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <cstring>
using namespace std;
class Sorting{
	private:
	//data, variable
	int s[100],bs[100],ss[100];//arry to store roll numbers
	int n;//number of students
	
	public:
	//Function to read roll numbers of students
	void readRollNos(){
		cout<<"\nEnter the number of students::";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Enter "<<i+1<<"th number:";
			cin>>s[i];
			bs[i]=ss[i]=s[i];
		}
	}
	
	//Print student List
	void printStudentList(){
		cout<<"\nThe student list is::";
		for(int i=0;i<n;i++)
			cout<<s[i]<<"  ";
	}
	
	//Bubble sort algorithms
	void bubbleSort(){
		int i,j,temp;
		bool flagSort=false;
		for(i=0; i<n;i++){
			flagSort=false;
			cout<<"\nPass-"<<i+1<<"\n";
			for(j=0;j<n-i-1;j++){
				if(bs[j] < bs[j+1]){
					flagSort=true;
					temp = bs[j];
					bs[j]=bs[j+1];
					bs[j+1]=temp;
				}
				for(int k=0;k<n;k++)
					cout<<bs[k]<<"  ";
				cout<<"\n";
			}
			if(!flagSort)
				break;
		}
		cout<<"\nSorted Student list\n";
		for(int k=0;k<n;k++)
				cout<<bs[k]<<"  ";
		cout<<"\n";
	}
	
	//Selection	sort algorithms
	void selectionSort(){
		int i,j,temp;
		for(i=0; i<n;i++){
			cout<<"\nPass-"<<i+1<<"\n";
			for(j=i+1;j<n;j++){
				if(ss[i] < ss[j]){
					temp = ss[i];
					ss[i]=ss[j];
					ss[j]=temp;
				}
				for(int k=0;k<n;k++)
					cout<<ss[k]<<"  ";
				cout<<"\n";
			}
		}
		cout<<"\nSorted Student list\n";
		for(int k=0;k<n;k++)
				cout<<ss[k]<<"  ";
		cout<<"\n";
	}
	
	//Print top five scores
	void topFiveScore(int pref){
		int i;
		if(pref==0){
			
			if(n==0)
				cout<<"\nStudent list Empty!";
			else
				if(n>=5){
					cout<<"\nTop 5 scores are:";
						for(i=0;i<5;i++)
							cout<<bs[i]<<"  ";
				}
				else{
					cout<<"\nTop "<<n<<" scores are:";
						for(i=0;i<n;i++)
							cout<<bs[i]<<"  ";
				}
		}
		else if (pref==1){
				if(n==0)
					cout<<"\nStudent list Empty!";
				else
					if(n>=5){
						cout<<"\nTop 5 scores are:";
							for(i=0;i<5;i++)
								cout<<ss[i]<<"  ";
					}
					else{
						cout<<"\nTop "<<n<<" scores are:";
							for(i=0;i<n;i++)
								cout<<ss[i]<<"  ";
					}
		}
		else
			cout<<"\nYou have only two choices!!";
	}
};
int main(){
	Sorting stud;
	int choice=0,key,pref;
	while(choice != 6){
		cout<<"\n****************Sorting Operation**************";
		cout<<"\n1. Read Percent";
		cout<<"\n2. Display student list";
		cout<<"\n3. Sort student using Bubble Sort";
		cout<<"\n4. Sort student using Selection Sort";
		cout<<"\n5. Top 5 scores";
		cout<<"\n6. Exit";
		cout<<"\nWhat operation you want::";
		cin>>choice;
		switch(choice){
			case 1:
				stud.readRollNos();
				break;
			case 2:
				stud.printStudentList();
				break;
			case 3:
				cout<<"\nBubble Sort OUTPUT:";
				stud.bubbleSort();
				break;
			case 4:
				cout<<"\nSection Sort OUTPUT:";
				stud.selectionSort();
				break;
			case 5:
				cout<<"\nWhat Sort result you want (0-Bubble, 1-Selection)::";
				cin>>pref;
				stud.topFiveScore(pref);
				break;
			case 6:
				cout<<"\nThanks for using application!!";
				break;
			default:
				cout<<"\nWrong Choice!!";
		}
	}
	
	return 0;
}