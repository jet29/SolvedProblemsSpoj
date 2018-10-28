#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	
	long long int n;
	
	cin>>n;
	
	
	while(n>1){
		if(n % 2 != 0){
			printf("NIE");
			return 0;
		}
		if(n == 3 || n == 5 || n == 7 || n == 9 || n == 10){
			printf("NIE");
			return 0;
		}
		n = n/2;
	}
	
	printf("TAK");
	
	return 0;
}
