/*
AIM:
Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of second, third and final year of department 
can be   membership on request.
Similarly, onemay cancel the membership of club.
First node is reserved for president of club and last node is 
reserved for secretary of club.
Write C++ program to maintain club member ‘information using 
singly linked list. Store student PRN and Name.
Write functions to:
a) Add and delete the members as well as president 
or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exist for two divisions. Concatenate two lists.


INPUT: Student PRN name and member Type
OUTPUT:Two Linked List for SY-Div-A & SY-Div-B
 
Author: Sunil Rathod
Date: 11.09.2025
*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <cstring>
#define MAX 50
using namespace std;
//ADT Student
struct Student{
	int PRN;//Student PRN
	string name;//Student
	string memberType;//Member , regular, president or secretary
	Student *next;
};

//Implementation Class
class PinnacleClub{
	private:
		Student *headSYDIVA;//Header for SY-Div-A
		Student *headSYDIVB;//Header for SY-Div-B
		Student *headSYAB;//Header for both DIVISIONS of SY
		
	public:
		PinnacleClub(){
			headSYDIVA=NULL;
			headSYDIVB=NULL;
		}
		
		//###################SY-Div-A##########################
		void addNodeSYA(int prn ,string name,int memberType){
			Student *p;
			p=new Student;
			p->PRN=prn;
			p->name=name;
			if(memberType == 1)
				p->memberType="regular";
			else if(memberType == 2)
				p->memberType="president";
			else if(memberType == 3)
				p->memberType="secretary";
				
			p->next=NULL;
			
			if(headSYDIVA == NULL)
				headSYDIVA=p;
			else{
				//if member node is regular
				if(p->memberType=="regular"){
						Student *cur,*f;
						cur=headSYDIVA;
						while(cur->next != NULL){
							f=cur;
							cur=cur->next;
						}
					
						if(cur->memberType=="secretary"){
							//If secretary if first node and a last node
							if(cur==headSYDIVA){
								headSYDIVA=p;
								p->next=cur;
							}
							else{
								p->next=cur;
								f->next=p;
							}		
						}
						else
							cur->next=p;
					}//end if regular
					else
					if(p->memberType=="secretary"){
						Student *cur,*f;
						cur=headSYDIVA;
						while(cur->next != NULL){
							f=cur;
							cur=cur->next;
						}
						//
						if(cur->memberType != "secretary")
							cur->next=p;
						else
							cout<<"\nSecretrary already exists!!";
						
					}//end if secretary
					else
					if(p->memberType=="president"){
						Student *cur,*f;
						cur=headSYDIVA;
						if(cur->memberType != "president"){
							p->next=cur;
							headSYDIVA=p;
						}
						else
							cout<<"\nPresident already exists!!";
						
					}//end if president
				
			}//end else
		}
	
		//Function to delete member in LL
		void deleteNodeSYA(int prn){
			Student *cur,*prev;
			
			if(headSYDIVA==NULL)
				cout<<"\nList Empty!!";
			else{
				cur=headSYDIVA;
				while(cur !=NULL ){
					if(cur->PRN == prn)
						break;
					prev=cur;
					cur=cur->next;
				}
				if(cur==NULL)
					cout<<"\nPRN no. not found!!";
				else{
					//Node is first as well as last node
					if(headSYDIVA==cur && cur->next==NULL){
						headSYDIVA=NULL;
						delete cur;
					}
					else //Node is first node followed by one or more nodes
						if(headSYDIVA==cur && cur->next != NULL){
						headSYDIVA=headSYDIVA->next;
						delete cur;
					}
					else //Node is last node have one or more nodes as prev nodes
						if(headSYDIVA !=cur && cur->next ==NULL){
						prev->next=NULL;
						delete cur;
					}	
					else{
						prev->next = cur->next;
						delete cur;
					}
				}//end else member found
			}//end else List is not empty
		}
		
		//Function to count members in LL
		int countMembersSYA(){
			int count=0;
			Student *cur=headSYDIVA;
			while(cur != NULL){
				count++;
				cur=cur->next;
			}
			return count;
		}
		
		//Function to display List member in LL
		void displayListSYA(){
			Student *cur;
			cur=headSYDIVA;
			cout<<"\nheadSYA-->";
			while(cur != NULL){
				cout<<"["<<cur->PRN<<"|"<<cur->name<<"|"<<cur->memberType<<"]-->";
				cur=cur->next;
			}
			cout<<"NULL";
		}
		
		//###################SY-Div-B##########################
		void addNodeSYB(int prn ,string name,int memberType){
			Student *p;
			p=new Student;
			p->PRN=prn;
			p->name=name;
			if(memberType == 1)
				p->memberType="regular";
			else if(memberType == 2)
				p->memberType="president";
			else if(memberType == 3)
				p->memberType="secretary";
				
			p->next=NULL;
			
			if(headSYDIVB == NULL)
				headSYDIVB=p;
			else{
				//if member node is regular
				if(p->memberType=="regular"){
						Student *cur,*f;
						cur=headSYDIVB;
						while(cur->next != NULL){
							f=cur;
							cur=cur->next;
						}
					
						if(cur->memberType=="secretary"){
							//If secretary if first node and a last node
							if(cur==headSYDIVB){
								headSYDIVB=p;
								p->next=cur;
							}
							else{
								p->next=cur;
								f->next=p;
							}		
						}
						else
							cur->next=p;
					}//end if regular
					else
					if(p->memberType=="secretary"){
						Student *cur,*f;
						cur=headSYDIVB;
						while(cur->next != NULL){
							f=cur;
							cur=cur->next;
						}
						//
						if(cur->memberType != "secretary")
							cur->next=p;
						else
							cout<<"\nSecretrary already exists!!";
						
					}//end if secretary
					else
					if(p->memberType=="president"){
						Student *cur,*f;
						cur=headSYDIVB;
						if(cur->memberType != "president"){
							p->next=cur;
							headSYDIVB=p;
						}
						else
							cout<<"\nPresident already exists!!";
						
					}//end if president
				
			}//end else
		}
	
		//Function to delete member in LL
		void deleteNodeSYB(int prn){
			Student *cur,*prev;
			
			if(headSYDIVB==NULL)
				cout<<"\nList Empty!!";
			else{
				cur=headSYDIVB;
				while(cur !=NULL ){
					if(cur->PRN == prn)
						break;
					prev=cur;
					cur=cur->next;
				}
				if(cur==NULL)
					cout<<"\nPRN no. not found!!";
				else{
					//Node is first as well as last node
					if(headSYDIVB==cur && cur->next==NULL){
						headSYDIVB=NULL;
						delete cur;
					}
					else //Node is first node followed by one or more nodes
						if(headSYDIVB==cur && cur->next != NULL){
						headSYDIVB=headSYDIVB->next;
						delete cur;
					}
					else //Node is last node have one or more nodes as prev nodes
						if(headSYDIVB !=cur && cur->next ==NULL){
						prev->next=NULL;
						delete cur;
					}	
					else{
						prev->next = cur->next;
						delete cur;
					}
				}//end else member found
			}//end else List is not empty
		}
		
		//Function to count members in LL
		int countMembersSYB(){
			int count=0;
			Student *cur=headSYDIVB;
			while(cur != NULL){
				count++;
				cur=cur->next;
			}
			return count;
		}
		//Function to display List member in LL
		void displayListSYB(){
			Student *cur;
			cur=headSYDIVB;
			cout<<"\nheadSYB-->";
			while(cur != NULL){
				cout<<"["<<cur->PRN<<"|"<<cur->name<<"|"<<cur->memberType<<"]-->";
				cur=cur->next;
			}
			cout<<"NULL";
		}	
		//######################Merge two division lists##############################
		//Concatenate Two Lists
		void concatenate(){
			Student *cur;
			
			//Both the lists are empty
			if (headSYDIVA == NULL && headSYDIVB == NULL){
				headSYAB=NULL;
				cout<<"Lists are empty!!";
			}
			else //The list of SY-DIV-A is empty
			if (headSYDIVA == NULL && headSYDIVB != NULL){
				headSYAB=headSYDIVB;
				headSYDIVB=NULL;
			}
			else //The list of SY-DIV-B is empty
			if (headSYDIVA != NULL && headSYDIVB == NULL){
				headSYAB=headSYDIVA;
				headSYDIVA=NULL;
			}
			else//Both lists have some members
			{
				cur=headSYDIVA;
				//Go to the end of first list 
				while(cur->next !=NULL)
					cur=cur->next;
				//connect last node of SY-DIV-A to the first node of SY-DIV-B
				cur->next=headSYDIVB;
				//set the header of both the division to headSYDIVA
				headSYAB=headSYDIVA;
				//make SY-DIV-A & SY-DIV-B list pointers NULL
				headSYDIVA=headSYDIVB=NULL;
			}
		}
		
		//Display Merged List
		void displayListSY(){
			Student *cur;
			cur=headSYAB;
			cout<<"\nheadSY-->";
			while(cur != NULL){
				cout<<"["<<cur->PRN<<"|"<<cur->name<<"|"<<cur->memberType<<"]-->";
				cur=cur->next;
			}
			cout<<"NULL";
		}	
		
};

int main(){
	PinnacleClub P;
	int choice=0,prn,memberType,subChoice;
	string name;
	while(choice != 6){
		cout<<"\n****************Pinnacle Club Operations**************";
		cout<<"\n1. Add Student";
		cout<<"\n2. Display List";
		cout<<"\n3. Delete Student";
		cout<<"\n4. Count Members in List";
		cout<<"\n5. Concatenate two lists";
		cout<<"\n6. Exit";
		cout<<"\nWhat operation you want::";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"\nEnter Student PRN::";
				cin>>prn;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
				cout<<"\nEnter Student Name::";
				cin>>name;
				cout<<"\nEnter Student member type 1-regular, 2-president, 3-secretary::";
				cin>>memberType;
				cout<<"\nWhich list 1-SY DIV-A, 2-SY DIV-B::";
				cin>>subChoice;
				if(subChoice==1)
					P.addNodeSYA(prn,name,memberType);
				else if(subChoice==2)
					P.addNodeSYB(prn,name,memberType);
				
				break;
			case 2:
				P.displayListSYA();
				P.displayListSYB();
				break;
			case 3:
				cout<<"\nWhich list 1-SY DIV-A, 2-SY DIV-B::";
				cin>>subChoice;
				if(subChoice==1)
					P.deleteNodeSYA(prn);
				else if(subChoice==2)
					P.deleteNodeSYB(prn);
				break;
			case 4:
				cout<<"\nThe number of members in SY Div-A List are::"<<P.countMembersSYA();
				cout<<"\nThe number of members in SY Div-B List are::"<<P.countMembersSYB();
				break;
			case 5:
				cout<<"\nThe Merged List of both the Divisions is::\n";
				P.concatenate();
				P.displayListSY();
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