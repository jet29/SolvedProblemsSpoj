#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;



int main(){
	
	map<string,int> puntaje;
	string maxTeam;
	
	int c;
	scanf("%d",&c);
	
	for(int i = 0; i<c; i++){
		
		puntaje.clear();
		maxTeam = "";
		
		for(int j = 0; j < 16; j++){
			
			string team1;
			string team2;
			int score1;
			int score2;
			
			cin>>team1;
			cin>>team2;
			cin>>score1;
			cin>>score2;
			
			if(score1 > score2){
				puntaje[team1]++;
				puntaje[team2]--;
			}
			
			if(score2 > score1){
				puntaje[team2]++;
				puntaje[team1]--;
			}
				
		}
		
		int max = -999;
		
		for (map<string,int>::iterator it=puntaje.begin(); it!=puntaje.end(); ++it){
			if(max < it->second){
				maxTeam = it->first;
				max = it->second;
			}
		}	
		
		cout<<maxTeam<<endl;
	}
	

	
	return 0;
}
