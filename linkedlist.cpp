#include <iostream>
using namespace std;
class node {
	public:
		int data;
		node *next;
};

class linkedList {
	node *head, *tail;
	public:
		linkedList()
		{
			head= NULL;
			tail= NULL;
		}
		void createNode(int value)
		{
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if (head == NULL)
			{
				head= temp;
				tail = temp;
				temp = NULL;
			}
			else
			{
				tail -> next = temp;
				tail=temp;
				temp=NULL;
			}
		}
		void insertNode(int pos, int value)
		{
			node *temp;
			temp= new node;
			node *prev;
			node *cur;
			int i;
			cur = head;
			for(i=1;i<pos;i++)
			{
				prev=cur;
				cur = cur->next ;	
			}
			temp->data=value;
			temp->next=cur;
			prev->next=temp;
		}
		void displayList()
		{
			node *temp;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data << "\t";
				temp=temp->next;
			}
		}
		void deleteNode(int pos){
			node *temp=NULL;
			node *cur=NULL;
			node *prev=NULL;
			int i;
			for(i=1;i<pos;i++){
				prev=cur;
				cur=cur->next;
			}
			prev->next=cur->next;
			delete cur;
		}
};

int main(){
	linkedList obj;
	obj.createNode(5);
	obj.createNode(25);
	obj.createNode(46);
	obj.displayList();
	cout<<"\n";
	//int n;
	//cout<< "enter value to be added to the list" <<endl;
	//cin>>n;
	obj.insertNode(2, 6);
	obj.displayList();
	cout<<"\n";
	obj.deleteNode(3);
	obj.displayList();
	return 0;
	}
