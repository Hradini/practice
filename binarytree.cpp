#include<iostream>
using namespace std;

struct node{
	int data;
	node* parent;
	node* left;
	node* right;
	
	bool hasLeft(){
		if (left!=NULL) return true;
		else return false;
	}
	bool hasRight(){
		if(right!=NULL) return true;
		else return false;
	}
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
						temp->parent=cur;
						break;
					}
					else{
						cur=cur->left;
					}
				}
				else{
					if(cur->right==NULL){
						cur->right=temp;
						temp->parent=cur;
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
		cout<<temp->data<<" ";
		display(temp->right);
	}
	node* bsearch(int key, node* cur){
	cout<<cur->data<<endl;
		if(cur==NULL) return NULL;
		if(key < cur->data) bsearch(key, cur->left);
		else if(cur->data==key){		
			if(cur->parent!=NULL) cout<<"Parent of the node"<<(cur->parent)->data;
			if(cur->left!=NULL) cout<<"Left child"<<(cur->left)->data<<endl;
			if(cur->right!=NULL) cout<<"Right child"<<(cur->right)->data<<endl;
			return cur;
		}
		else 
		bsearch(key, cur->right);
	}
	void DeleteNode(int key, node *cur){
		node* temp;
		temp= bsearch(key, cur);
		if(temp!=NULL){
			if(!temp->hasLeft() && !temp->hasRight()){
				if(temp->data > (temp->parent)->data){
					(temp->parent)->right = NULL;
				}else{
					(temp->parent)->left = NULL;
				}
				delete temp;
			}
			else if(!temp->hasLeft() || !temp->hasRight())
			{
				if(temp->left==NULL)
				{
					if(temp->data < (temp->parent)->data){					
						(temp->parent)->left= temp->right;
						(temp->right)->parent=temp->parent;
					}
					else{					
						(temp->parent)->right= temp->right;
						(temp->right)->parent=temp->parent;
					}
				}
				else{
						if(temp->data < (temp->parent)->data){					
						(temp->parent)->left= temp->left;
						(temp->left)->parent=temp->parent;
					}
					else{					
						(temp->parent)->right= temp->left;
						(temp->left)->parent=temp->parent;
					}
				}
				delete temp;
			}
			else{
				node* min;
				min=temp->right;
				while(min->left!=NULL){
					min=min->left;
				}
				cout<<endl<<min->data;
				min->right= (min->parent)->left;
				(min->right)->parent=min->parent;
				min->parent=temp->parent;
				if((min->parent)->data > min->data) (min->parent)->left=min;
				else (min->parent)->right=min;
				min->right=temp->right;
				(temp->right)->parent=min;
				min->left=temp->left;
				(temp->left)->parent=min;
				
				delete temp;
			}
	}

}
};
int main(){
	Btree bt1;
	bt1.insert(5);
	bt1.insert(2);
	bt1.insert(17);
	bt1.insert(6);
	bt1.insert(1);
	bt1.insert(18);
	bt1.insert(9);
	bt1.insert(10);
	bt1.display(bt1.root);
	cout<<"Enter key";
	int key;
	cin>> key;
	bt1.bsearch(key, bt1.root);
	cout<<"Enter data to be deleted"<<endl;
	cin>>key;
	bt1.DeleteNode(key, bt1.root);
	bt1.display(bt1.root);
}
