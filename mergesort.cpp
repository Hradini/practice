#include <iostream>
using namespace std;

void display(int arr[], int size){
	int i=0;
	while(i<size){
		cout<<arr[i];
		i++;
	}
}

void merge(int arr[], int low, int mid, int high, int marr[]){
	int l=low;
	int h=high;
	int m=mid;
	int k=0;
	while(k<2*(high-low)){
		if(arr[l]<arr[m+1]){
			marr[k]=arr[l];
			l++;
			k++;
		}
		else{
			marr[k]=arr[m+1];
			m++;
			k++;
		}
	}
}

int mergesort(int arr[], int low, int high, int marr[]){
	int mid=(low+high)/2;
	if(low<high){
		mergesort(arr, low, mid, marr);
		mergesort(arr, mid+1, high, marr);
		merge(arr, low, mid, high, marr);
	}
	else{
	return 0;
	}
}

int main(){
	int size=10;
	int marr[size];
	int arr[10]={5,6,2,9,0,1,3,8,4,7};
	int i=0;
	/*while(i!=size-1){
		cout<<"enter number";
		cin>>arr[i];
		i++;
	}*/
	mergesort(arr,0,9, marr);
	i=0;
	/*while(i!=size-1){
		cout<<marr[i];
		i++;
	}*/
	display(marr,10);
	cout<<endl;
	return 0;
}			

	

