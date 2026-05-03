/*
AIM: Write a C++ program 
to store roll numbers of student in array who attended training 
program in random order. 
Write function for searching 
whether particular student attended training program or not, 
using Linear search and binary search. 
Compare these two algorithms with respect to the number of 
comparisons required to find the given students

INPUT: Read Roll numbers of students
OUTPUT:
a) find student using Linear Search
b) find student using binary search

Author: Sunil Rathod
Date: 29.07.2025
*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <cstring>
using namespace std;
class Searching{
	private:
	//data, variable
	int s[100];//arry to store roll numbers in unsorted form
	int bs[100];//arry to store roll numbers in sorted form to perform binary search
	int n;//number of students
	
	public:
	//Function
	void readRollNos(){
		cout<<"\nEnter the number of students::";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Enter "<<i+1<<"th number:";
			cin>>s[i];
			bs[i]=s[i];
		}
	}
	void printStudentList(){
		cout<<"\nThe student list is::";
		for(int i=0;i<n;i++)
			cout<<s[i]<<"  ";
	}
	
	void linearSearch(int key){
		int i;
		for(i=0;i<n;i++){
			if(key == s[i]){
				cout<<"\nStudent found at location "<<i+1<<" with "<<i+1<<" Comparisions";
				break;
			}
		}
		if(i==n)
			cout<<"\nStudent NOT found!"<<" with "<<i+1<<" Comparisions";;
	}
	
	void selectionSort(){
		int i,j,temp;
		for(i=0; i<n;i++){
			for(j=i+1;j<n;j++){
				if(bs[i] > bs[j]){
					temp = bs[i];
					bs[i]=bs[j];
					bs[j]=temp;
				}	
			}
		}
		cout<<"\nSorted Student list\n";
			for(int k=0;k<n;k++)
				cout<<bs[k]<<"  ";
	}
	
	void binarySearch(int key){
		int l,u,mid,count=0;
		l=0;
		u=n-1;
		while(l<=u){
			mid=(l+u)/2;
			count++;
			if(key == bs[mid]){
				cout<<"\nStudent found at location "<<mid+1<<" with "<<count<<" Comparisions";
				break;
			}
			else if(key > bs[mid])
				l=mid+1;
			else
				u=mid-1;
		}
		if(l>u)
			cout<<"\nStudent NOT found!"<<" with "<<count<<" Comparisions";;
	}
	
};
int main(){
	Searching stud;
	int choice=0,key;
	while(choice != 5){
		cout<<"\n****************Search Operations**************";
		cout<<"\n1. Read roll numbers";
		cout<<"\n2. Display Student List";
		cout<<"\n3. Find Student using Linear Search";
		cout<<"\n4. Find Student using Binary Search";
		cout<<"\n5. Exit";
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
				cout<<"\nEnter number to be searched:";
				cin>>key;
				stud.linearSearch(key);
				break;
			case 4:
				cout<<"\nEnter number to be searched:";
				cin>>key;
				stud.selectionSort();// First sort the elements of an array
				stud.binarySearch(key);//Perform the binary search
				break;
			case 5:
				cout<<"\nThanks for using application!!";
				break;
			default:
				cout<<"\nWrong Choice!!";
		}
	}
	return 0;
}