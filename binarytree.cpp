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
	void bsearch(int key, node* cur){
	cout<<cur->data<<endl;
		if(cur==NULL) return;
		if(key < cur->data) bsearch(key, cur->left);
		else if(cur->data==key){
			if(cur->parent!=NULL) cout<<"Parent of the node"<<(cur->parent)->data;
			if(cur->left!=NULL) cout<<"Left child"<<(cur->left)->data<<endl;
			if(cur->right!=NULL) cout<<"Right child"<<(cur->right)->data<<endl;
		}
		else 
		bsearch(key, cur->right);
			
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
	cout<<"Enter key";
	int key;
	cin>> key;
	bt1.search(key, bt1.root);
	
}	
			
