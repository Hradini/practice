#include <iostream>
using namespace std;

int heap[100];
int length=0;

void insert(int key)
{	heap[length]=key;
	int i= length;
	if(length!=0){
		int p,temp;
		p=(i-1)/2;
		while(heap[i]>=heap[p] && i!=0)
		{	temp=heap[i];
			heap[i]=heap[p];
			heap[p]=temp;		
			i=p;
			p=(i-1)/2;
		}
		
	}
	length++;
}

void display(int *a)
{	for(int i=0; i<length; i++)
	{	cout<< a[i] <<"\t";
	}
	cout<<endl;
}
void remove(){
	heap[0]=heap[length];
	length--;
	int j=0;
	int temp;
	//cout<<"hello";
	if( ((2*j)+1) <=length){
		while(heap[(2*j)+1]<heap[j] && heap[(2*j)+2]<heap[j]){
		
			if (((2*j)+1)<=length && ((2*j)+2)<=length){
				if(heap[(2*j)+1]>heap[(2*j)+2]){
					if(heap[(2*j)+1]>heap[j]){
						temp=heap[(2*j)+1];
						heap[(2*j)+1]=heap[j];
						heap[j]=temp;
						j=(2*j)+1;
					}
				}else{
					if(heap[(2*j)+2]>heap[j]){
						temp=heap[(2*j)+2];
						heap[(2*j)+2]=heap[j];
						heap[j]=temp;
						j=(2*j)+2;
					}
				}
			}
			else if(((2*j)+1)<=length && heap[(2*j)+1]>heap[j]){
				temp=heap[(2*j)+1];
				heap[(2*j)+1]=heap[j];
				heap[j]=temp;
				j=(2*j)+1;	
			}	
		}
	}
}
	
	
	
int main()
{	int key;
	int choice;
	int flag=1;
	while(flag)
	{	cout<< " 1 - Insert value in heap" <<endl<<" 2 - Display heap"<<endl<<" 3 - Remove root " <<endl<< " 4 - Exit"<<endl;
		cin >> choice;
		switch(choice){
			case 1:
			cout<<"Enter the value";
			cin>>key;
			insert(key);
			break;
			case 2:
			display(heap);
			break;
			case 3:
			//cout<<"remove";
			remove();
			break;
			case 4:
			flag=0;
			break;
		}
	}
	return 0;
}

			
