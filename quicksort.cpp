#include <iostream>
using namespace std;

void quicksorta(int arr[],int left,int right){
	int i,j;
	int temp;
	i=left;
	j=right;
	int pivot= arr[(left+right)/2];
	int flagi=0,flagj=0;
	//it does not seem to be entering this while loop even when i<j
	while(i<j){
		if(arr[i]<=pivot){
			++i;
			flagi=1;
		
		}
		if(arr[j]>pivot){
			--j;
			flagj=1;
			
		}
		if(i<j && flagi==flagj==0){
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			++i;
			--j;
			flagi=flagj=0;
			
		}
	}
	if(left!=right){
		quicksorta(arr,left,i);
		quicksorta(arr,j,right);
	}
	
}


void display(int arr[]){
	for(int i=0;i<6;++i){
		cout<<arr[i];	
	}
}

int main(){
	int arr[6]={7,2,3,4,8,1};
	int left=0;
	int right=5;
	display(arr);
	quicksorta(arr,0,5);
	display(arr);
}
