#include <stdio.h>
#include <stdlib.h>

int *cantUsadas;
char *p; 
int cont;

void permutar(int n,int casilla){ //al inicio se pasa (n,1)

	for(int i = 0; i < n; i++){
		
		if(i == 0){
			cantUsadas[i]++;
			casilla++;
			
			if(casilla == n){
				cont++;
			}
			else{	
				permutar(n,casilla);
			}
			cantUsadas[i]--;
			casilla--;
				
		}
		else{
			if(cantUsadas[i-1] > 0){
				cantUsadas[i]++;
				casilla++;
				
				if(casilla == n){
					cont++;
				}
				else{	
					permutar(n,casilla);
				}
			
				casilla--;
				cantUsadas[i]--;
			}
		}
	}
		
}

int main(){
	int t;
	scanf("%d",&t);
	int numbers[t];
	for(int i = 0; i < t; i++)scanf("%d",&numbers[i]);
	
	



	for(int i = 0; i < t; i++){
		if(numbers[i] != 1){
			cont = 0;
			p = (char*)malloc(sizeof(char) * numbers[i]);
			cantUsadas = (int*)malloc(sizeof(int)* numbers[i]);
			
			p[0] = 'a'; //axioma
			
			cantUsadas[0] = 1;
			for(int j = 1; j < numbers[i];j++)cantUsadas[j]=0;
			
			permutar(numbers[i],1);
			free(p);
			free(cantUsadas);
			/*devuelvo valores */
	
			
			printf("%d\n",cont);
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}
