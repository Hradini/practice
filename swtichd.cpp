    #include <iostream>
    #include <cmath>
    using namespace std;
    int digits(int num){
    	int count=0;
    	while (num!=0){
    		num /= 10;
    		count ++;
    	}
    	return count;
    }
    int main() {
    	cout << "enter your number\n";
    	int num,i;
    	cin >> num;
    	int d= digits(num);
    	int c=d;
    	int arr[d];
    	while(num!=0){
    		arr[d-1]= num%10;
    		num /= 10;
    		d--;
    	}
    	cout << "enter the which digit must be interchanged\n";
    	int d1,d2;
    	cin >> d1 >> d2;
    	int temp;
    	temp=arr[d1-1];
    	cout << temp << endl;
    	arr[d1-1]=arr[d2-1];
    	arr[d2-1]=temp;
    	int newnum=0;
    	for(i=c; i!=0;i--){
    		newnum += (arr[i-1]*pow(10,c-i));
     
    	}
    	cout << newnum;
    	return 0;
    }
