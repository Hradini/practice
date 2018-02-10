#include <iostream>
using namespace std;

void quicksorta(int arr[],int left,int right){
	int i,j;
	int temp;
	i=left;
	j=right;
	int pivot= arr[(left+right)/2];
	int flagi=0,flagj=0;
	
	while(i<j){
		if(arr[i]<=pivot){
			++i;
			flagi=1;
		
		}
		if(arr[j]>pivot){
			--j;
			flagj=1;
			
		}
		if(i<j && flagi==0 && flagj==0){
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			++i;
			--j;
			flagi=flagj=0;
			cout<<"hello";
		}
	}
	if(left<i){
		cout<<"left partion has happened";
		quicksorta(arr,left,i);
	}
	if(right>j){
		cout<<"right partion has happened";
		quicksorta(arr,j,right);
	}
	
}


void display(int arr[]){
	for(int i=0;i<6;++i){
		cout<<arr[i]<<"\t";	
	}cout<<endl;
}

int main(){
	int arr[6]={7,2,3,4,8,1};
	int left=0;
	int right=5;
	display(arr);
	quicksorta(arr,0,5);
	display(arr);
}
