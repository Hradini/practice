#include<iostream>
using namespace std;

struct node{
	int data;
	node* parent;
	node* left;
	node* right;
};

class Btree{
	public:
	node* root;
	Btree(){ 
	root=NULL;
	}
	
	void insert(int data){
		node* temp = new node;
		temp->data= data;
		temp->parent=temp->left=temp->right=NULL;
		
		if(root==NULL){
			root=temp;
		}
		else{
		node* cur= new node;
		cur=root;
			while(true){
				if((cur->data)>(temp->data)){
					if(cur->left==NULL){
						cur->left=temp;
						break;
					}
					else{
						cur=cur->left;
					}
				}
				else{
					if(cur->right==NULL){
						cur->right=temp;
						break;
					}
					else{
						cur=cur->right;
					}
				}
			}
		}
	}
	
	void display(node* temp){
		if(temp==NULL) return;
		display(temp->left);
		cout<<temp->data;
		display(temp->right);
	}
};

int main(){
	Btree bt1;
	bt1.insert(5);
	bt1.insert(2);
	bt1.insert(7);
	bt1.insert(1);
	bt1.insert(8);
	bt1.display(bt1.root);
	
}	
			
