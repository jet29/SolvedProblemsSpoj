#include <stdio.h>

int main(){
	
	int t;
	scanf("%d",&t);
	
	int n,m, D;
	
	for(int j = 0; j < t; j++){
		
		scanf("%d",&n);
		scanf("%d",&m);
		scanf("%d",&D);
		
		int H[n];
		
		for(int i = 0; i < n; i++){
			scanf("%d",&H[i]);
		}
		
		int intentos = 0;
		
		for(int i = 0; i < n; i++){
			
			if(H[i] % D == 0){
				intentos+= (H[i]/D) - 1;
			}
			else{
				if(H[i] / D < 1)
					continue;
				
				intentos+= (H[i]/D);
			}
			
		}
		
		if(intentos >= m){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	
	}
	

	return 0;
}
