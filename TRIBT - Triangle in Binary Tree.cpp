#include <stdio.h>

int cantIs; //cantidad de isosceles

class Node{
	public:
		Node *left;
		Node *right;
		int father;
		int arrayPos;
		
		Node(int _father, int _arrayPos){
			father = _father;
			arrayPos = _arrayPos;
			left = NULL;
			right = NULL;
		}
};

Node *getTree(int *treeArray, int rLength){
	Node *arrayNodes[rLength];
	Node *root;
	
	for(int i = 0; i < rLength; i++){
		arrayNodes[i] = new Node(treeArray[i],i);
	}
	
	for(int i = 0; i < rLength; i++){
		int father;
		father = treeArray[i];
		
		if(father == -1){
			root = arrayNodes[i];
			continue;
		}
	
		//coloco al nodo como hijo de su padre
		if(arrayNodes[father]->left == NULL){
			//si no tiene hijo izquierdo lo coloco ahi
			arrayNodes[father]->left = arrayNodes[i];
		}
		else{
			//lo coloco en el lado derecho
			arrayNodes[father]->right = arrayNodes[i];
		}
	}
	
	return root;
}


void preOrder(Node *root){
	if(root == NULL)
		return;
		
	printf("%d \n",root->arrayPos);
	preOrder(root->left);
	preOrder(root->right);
}

void findIsosceles(Node *root){
	
	if(root == NULL)
		return;
		
	//buscamos los triangulos de profundidad
	
	Node *left, *right;
	left = root->left;
	right = root->right;
		
	while(left != NULL && right != NULL){
		cantIs++;
		left = left->left;
		right = right->right;	
	}

	left = root->left;
	right = root->right;

	int cantR = 0;
	int cantL = 0;
	
	//lado izquierdo
	
	while(left != NULL){
		cantL++;
		
		Node *aux = left->right;
		int auxCant = cantL;
		
		while(true){
			
			if(aux == NULL)
				break;
			
			auxCant--;
			if(aux != NULL && auxCant == 0){
				cantIs++;
				break;
			}
	
			aux = aux->right;
		}
		
		left = left->left;
		
	}
	
	//lado derecho
	
	while(right != NULL){
		cantR++;
		
		Node *aux = right->left;
		int auxCant = cantR;
		
		while(true){
			
			if(aux == NULL)
				break;
			
			auxCant--;
			if(aux != NULL && auxCant == 0){
				cantIs++;
				break;
			}
	
			aux = aux->left;
		}
		
		right = right->right;
		
	}
	
	findIsosceles(root->left);
	findIsosceles(root->right);		
}

int main(){
	
	cantIs = 0; 
	
	int T; //number of cases
	scanf("%d",&T);
	
	for(int i = 0; i < T; i++){
	
		int rLength;
		scanf("%d",&rLength); //lee el tamanio del array
		
		int treeArray[rLength];
		
		for(int i = 0; i < rLength; i++) //lee el array
			scanf("%d",&treeArray[i]);
			
		Node *root = getTree(treeArray, rLength);
		
		//preOrder(root);
		
		findIsosceles(root);
		
		printf("%d\n",cantIs);
		
		cantIs = 0;
			
	}
	
	
	return 0;
}
