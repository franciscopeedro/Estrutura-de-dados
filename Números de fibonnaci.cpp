#include <iostream>

using namespace std;

int fibonacci(int n){
	int fib=0;
	if(n==0){ 
		fib=0;
		return fib;
		}
	if(n==1 || n==2){
		fib=1;
		return fib;
	}
	else{
		return (fibonacci(n-1)+fibonacci(n-2));
	}
	
}


int main(){
	int n;
	cin>> n;
	cout << fibonacci(n);
}
