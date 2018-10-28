#include <iostream>
#include <math.h>
using namespace std;


int main()
{

	int number;
	cin>>number;
	
	bool primes[number];
	for(int i = 0; i < number; i++)
		primes[i] = true;
	
	for(int i = 2; i < pow(number,0.5); i++)
	{
		if(primes[i] == true)
		{
			for(int k = 0;k < number; k++)
			{
				int j = pow(i,2)+ k*i;
				if(j < number)
					primes[j] = false;
			}
		}
	}

	for(int i = 2; i < number; i++)
	{
		if(primes[i] == true)
		{
			cout<<i<<" ";
		}
	}

	return 0;		
}
