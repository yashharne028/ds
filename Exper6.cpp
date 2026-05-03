/*
AIM:
Pizza parlor accepting maximum M=15 orders.
Orders are served in first come first served basis. 
Order once placed cannot be cancelled.
Write C++ program to simulate the system using 
circular queue using array.

INPUT: Customer Order ID, Pizaa Quantity
OUTPUT: List of Customer Orders arrannged as circular queue

Author: Sunil Rathod
Date: 29.08.2025
*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#define MAX 100
using namespace std;
typedef struct Customer{
	int OID;//Order ID
	int Quantity;//Quantity
}CUST;
//ADT of CQueue
class CQueue{
	private:
		CUST Q[MAX];
		int front,rear;
	public:
		CQueue(){
			front=rear=-1;
		}
		
		bool isQueueEmpty(){
			if(front == -1)
				return true;
			else
				return false;
		}
		
		bool isQueueFull(){
			if((rear+1)%MAX == front)
				return true;
			else
				return false;
		}
		
		void enQueue(int oid,int qnt){
			if(!isQueueFull()){
				if(rear == -1){
					front=rear=0;
					Q[rear].OID=oid;
					Q[rear].Quantity=qnt;
				}
				else{
					rear=(rear+1)%MAX;
					Q[rear].OID=oid;
					Q[rear].Quantity=qnt;
				}
			}
			else
				cout<<"\nQueue Full";
		}
		
		void deQueue(){
			if(!isQueueEmpty()){
				if(front == rear)
					front=rear=-1;
				else
					front=(front+1)%MAX;
			}
			else
				cout<<"\nQueue Empty";
		}
		
		void printQueue(){
			int i;
			for(i=front;i!=rear;i=(i+1)%MAX)
				cout<<"["<<Q[i].OID<<"|"<<Q[i].Quantity<<"]  ";
			
			cout<<"["<<Q[i].OID<<"|"<<Q[i].Quantity<<"]";
		}
	
};

//Implementation Class
class PizzaParlor{
	private:
		int M;//Maximum number of orders accepted
		int OIDcount;//ID generate
		int tcount;//Total pizza order received
		CQueue q;// CQueue class object
	public:
		PizzaParlor(){
			OIDcount=0;
			tcount=0;
			M=20;
		}
		void acceptOrder(int qnt){
			if(tcount<M){
				if(qnt <= (M-tcount)){
					q.enQueue(++OIDcount,qnt);
					tcount=tcount+qnt;
				}
				else{
					char resp;
					cout<<"\nYou can get only "<<(M-tcount)<<" Pizza";
					cout<<"\nDo you want to continue with this nos. of pizza order (y/n)::";
					cin>>resp;
					if(resp == 'y' || resp == 'Y'){
						q.enQueue(++OIDcount,M-tcount);
						tcount=tcount+qnt;
					}
				}
			}
			else
				cout<<"\nNo more order can be accepted!!";
		}
		
		void serveOrder(){
			q.deQueue();
		}
		
		void orderStatus(){
			q.printQueue();
		}
};

int main(){
	PizzaParlor P;
	
	int choice=0,qnt;
	while(choice != 4){
		cout<<"\n****************Pizza Parlor Operations**************";
		cout<<"\n1. Take Order";
		cout<<"\n2. Serve Order";
		cout<<"\n3. Check Order Status";
		cout<<"\n4. Exit";
		cout<<"\nWhat operation you want::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nHow many pizza you want:";
				cin>>qnt;
				P.acceptOrder(qnt);
				break;
			case 2:
				P.serveOrder();
				break;
			case 3:
				P.orderStatus();
				break;
			case 4:
				cout<<"\nThanks for using application!!";
				break;
			default:
				cout<<"\nWrong Choice!!";
		}
	}
	return 0;

}
