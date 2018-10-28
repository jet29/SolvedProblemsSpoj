#include <math.h>
#include <stdio.h>


#define _USE_MATH_DEFINES

int main(){
	
	int num1 = 8;
	int num2 = 3;
	
	printf("%d",num1/num2);
	
	int N;
	scanf("%d",&N);
	
	for(int i = 0; i < N; i++){
		
		int numPies, numFriends;
		float maxVolume = 0;
		int partyMembers;
		
		scanf("%d",&numPies);
		scanf("%d",&numFriends);
		
		partyMembers = numFriends+1; 
		float piesRadius[numPies];
		
		for(int j = 0; j < numPies; j++){
			scanf("%f",&piesRadius[i]);
		}
		
		//caso en el que son mas pies que personas
		if(partyMembers > numPies){
			
			int extraPeople = partyMembers - numPies;
			
			
			int sharedPies = partyMembers % numPies;
			
		}
		
		
		
		
		
		
		
		for(int j = 0; j < numPies; j++){

			
			maxVolume += M_PI * pow(piesRadius[i],2);	
		}
		
		printf("el volumen maximo es: %f\n",maxVolume);
		printf("%f\n",maxVolume/(numFriends+1));
	}
	

	return 0;
}
