/*
AIM: Write a C++ program to compute following operations on String: 
a) To display word with the longest length 
b) To determines the frequency of occurrence 
of particular character in the string 
c) To check whether given string is palindrome or not 
d) To display index of first 
appearance of the substring 
e) To count the occurrences of each word in a given string

INPUT: Any string
OUTPUT:
a) Display longest length string
b) Find occurrence of particular character in the string 
c) To check string palindrome or not 
d) To display first index of substring 
e) To occurrences of each word in a given string

Author: Sunil Rathod
Date: 11.07.2025
*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;
class StringOperation{
	private	:
	//data, variable
	char s[100];
	
	public:
	//Function
	void readString(){
		cout<<"\nEnter any String::";
		cin.getline(s,100);	
	}
	
	void printString(){
		cout<<"\nThe string is ::"<<s;	
	}
	
	void longestWord(){
		int i=0,len=0,maxlen=0;
		while(s[i] != '\0'){
			if(s[i] != ' ')
				len++;
			else{
				if(len>maxlen)
					maxlen=len;
				len=0;
			}
			i++;
		}
		if(len>maxlen)
			maxlen=len;
		cout<<"\nMaximum lenght word is:"<<maxlen;
	}
	
	void frequencyChar(char ch){
		int i=0,freq=0;
		while( s[i] != '\0'){
			if(s[i] == ch)
				freq++;
			i++;
		}
		cout<<"\nThe character "<<ch<<" occured "<<freq<<" times";
	}
	
	int length(){
		int i=0;
		while(s[i] != '\0')
			i++;
		return i;
	}
	void palindrome(){
		int i,j;
		i=0;
		j=length()-1;
		
		while(i<=j){
			if(s[i] == s[j]){
				i++;
				j--;
			}
			else
				break;
		}
		if(i>=j)
			cout<<"\nGiven string is palindrome!!";
		else
			cout<<"\nGiven string is Not palindrome!!";
	}
	

	void firstIndexSubstring(char sub[]){
		int i,j,starti;
		i=0;
		j=0;
		starti=-1;
		while(s[i] != '\0'){
			
			while(sub[j] != '\0'){
				if(sub[j] != s[i]){
					j=0;
					starti=-1;
					break;
				}
				else{
					if(starti == -1)
						starti=i;
					i++;
					j++;
				}
			}
			i++;
		}
		if(starti != -1)
				cout<<"\nSub string found at start index "<<starti;
			else
				cout<<"\nSub string not found";
	}
	
	void findOccuranceOfWord(char word[]){
		int i,j,count=0;
		i=0;
		j=0;
		count=0;
		bool flag=false;
		while(s[i] != '\0'){
			
			while(word[j] != '\0'){
				if(word[j] != s[i]){
					j=0;
					flag=false;
					break;
				}
				else{
					flag=true;
					i++;
					j++;
				}
			}
			if(flag && (s[i] == ' ' ||  s[i] == '\0' ))
				count++;
			flag=false;
			j=0;
			
			i++;
		}
		if(count != 0)
				cout<<"\nword "<<word<<" found "<<count<<" times";
			else
				cout<<"\nword not found";
			
	}
	
	
	
};
int main(){
	StringOperation str;
	char sub[100];
	int choice=0;
	char ch;
	while(choice != 8){
		cout<<"\n******************String Operations*****************";
		cout<<"\n1. Read String";
		cout<<"\n2. Print String";
		cout<<"\n3. To display longest length word"; 
		cout<<"\n4. To find frequency of occurrence of a character in the string";
		cout<<"\n5. To check string is palindrome"; 
		cout<<"\n6. To display index of first appearance of the substring";
		cout<<"\n7.To count the occurrences of each word in a given string";
		cout<<"\n8. Exit Application";
		cout<<"\nWhat operation::";
		cin>>choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
		switch(choice){
			case 1:
				str.readString();
				break;
			case 2:
				str.printString();
				break;
			case 3:
				str.longestWord();
				break;
			case 4:
				cout<<"\nEnter any character to found:";
				cin>>ch;
				str.frequencyChar(ch);
				break;
			case 5:
				str.palindrome();
				break;
			case 6:
				cout<<"\nEnter sub string to be searched::";
				cin.getline(sub,100);
				str.firstIndexSubstring(sub);
				break;
			case 7:
				cout<<"\nEnter sub string to be searched::";
				cin>>sub;
				str.findOccuranceOfWord(sub);
				break;
			case 8:
				cout<<"\nThanks for using Application!!";
				break;
			default:
				cout<<"\nWrong choice!!";
		}
	}
	return 0;
}