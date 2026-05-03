/*
AIM:
In any language program mostly syntax error occurs 
due to unbalancing delimiter such as (),{},[].
Write C++ program using stack to check whether 
given expression is well parenthesized or not.

INPUT: An expression as string
OUTPUT: 
Display whether an expression is well parenthesized or not

Author: Sunil Rathod
Date: 21.08.2025
*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <cstring>
#define MAX 5
using namespace std;

//ADT of Stack
class Stack{
	private:
		char stk[MAX];
		int top;
	
	public:
		Stack(){
			top=-1;
		}
		bool isStackEmpty(){
			if(top==-1)
				return true;
			else
				return false;
		}
		
		bool isStackFull(){
			if(top==MAX-1)
				return true;
			else
				return false;
		}
		void push(char val){
			if(!isStackFull())
				stk[++top]=val;
			else
				cout<<"Stack Full";
		}
		
		char pop(){
			if(!isStackEmpty())
				return stk[top--];
			else
				cout<<"Stack Empty";
			
			return '\0';
		}
		
		void printStack(){
			int i;
			for(i=top;i>=0;i--)
				cout<<stk[i]<<"\n";
		}
};
//Implementation Class
class ExpressionParsing{
	private:
		char E[100];//To save the given mathematical expression
	
	public:
		void readExpression(){
			cout<<"\nEnter any mathematical expression::";
			cin.getline(E,100);
		}
		
		void printExpression(){
			cout<<"\nThe mathematical expression::";
			cout<<E;
		}
		
		void wellFormedExpression(){
			Stack obj;
			int i=0;
			char ch;
			bool flagValid=true;
			while(E[i] != '\0'){
				if(E[i] == '(' || E[i] == '{' || E[i] == '[' || E[i] == '<')
					obj.push(E[i]);
				else{
					if(E[i] == ')' || E[i] == ']' || E[i] == '}' || E[i] == '>'){
							ch=obj.pop();
							if(E[i] == ')' && ch != '(' || E[i] == ']' && ch != '[' || E[i] == '}' && ch != '{'|| E[i] == '>' && ch != '<')
								flagValid=false;
						}
				}
				i++;
			}
			if(obj.isStackEmpty()){
				if(flagValid)
					cout<<"\nThe Expression is well Formed Expression!";
				else
					cout<<"\nInvalid expression!";
			}
			else
				cout<<"\nThe Expression is NOT well Formed Expression!";
		}
};

int main(){
	ExpressionParsing exp;
	int choice=0;
	while(choice != 4){
		cout<<"\n****************Expression Parsing Operation**************";
		cout<<"\n1. Read Expression";
		cout<<"\n2. Print Expression";
		cout<<"\n3. Check Expression";
		cout<<"\n4. Exit";
		cout<<"\nWhat operation you want::";
		cin>>choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
		switch(choice){
			case 1:
				exp.readExpression();
				break;
			case 2:
				exp.printExpression();
				break;
			case 3:
				exp.wellFormedExpression();
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
