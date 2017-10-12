#include <iostream>
using namespace std;

int arrange(int arr[],int n){
	int i,j;
	
	for (i=0;i<n;++i){
		for(j=0;j<n-1-i; ++j){
			if(arr[j]>arr[j+1]){
				int temp= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;++i){
		cout << arr[i]<< " " ;
	}
}

int main() {
	int n,i;
	int arr[n];
	cout << "enter the size of the array\n";
	cin >> n;
	
	for (i=0;i<n;++i){
		cout<<"enter the" << i+1 << " element \n";
		cin >> arr[i];
	}
	for(i=0;i<n;++i){
		cout << arr[i]<< " " ;
	}cout <<endl;
	arrange(arr,n);
	
	return 0;
}
