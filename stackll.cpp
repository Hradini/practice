#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

struct stack{
	node *bottom;
	node *top;
	stack()
	{
		bottom=NULL;
		top=NULL;
	}
	void push(int value);
	void pop();
	void displayStack();
};

void stack::push(int value){
	node *temp=new node;
	temp->data = value;
	temp->next=NULL;
	if(top==NULL){
		temp->next=bottom;
		top->next = temp;
	}else{
		temp->next = top->next;
		top=temp;
	}
}  
void stack::pop(){
	node *temp=NULL;
	temp->next=top;
	top=top->next;
	delete temp;
}

void stack::displayStack(){
	node *temp=NULL;
	temp=top;
	while(temp!=NULL){
		cout <<temp->data <<"\n";
		temp=temp->next;
	}
}
	
int main(){
	stack obj;
	obj.push(11);
	obj.push(18);
	obj.push(47);
	obj.push(53);
	obj.displayStack();
	cout<<endl;
	obj.pop();
	obj.displayStack();
	return 0;
}
