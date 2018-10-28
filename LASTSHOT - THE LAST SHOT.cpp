#include<iostream>
#include<list>
#include<stdio.h>
using namespace std;

 
int maximumImpact = 0;
 
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;
 
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
    ~Graph();

	
	void clear();
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    int DFS();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph(){
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    maximumImpact++;
    visited[v] = true;
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
		if (!visited[*i]){			
        	DFSUtil(*i, visited);	
		}
	}
        

}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
int Graph::DFS()
{	
	int maximum = 0;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to print DFS traversal
    for (int i = 0; i < V; i++)
        if (visited[i] == false){
        	DFSUtil(i, visited);
        	if(maximumImpact > maximum)
        		maximum = maximumImpact;
        		
        	for(int j = 0; j < V; j++)
        		visited[j] = false;
        	maximumImpact = 0;
		}
		
	return maximum;
}

int main(){
		
	int n, m;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	Graph bombas(n);
	
	int a;
	int b;
	
	
	for(int j = 0; j < m; j++){
	
		scanf("%d",&a);
		scanf("%d",&b);
		
		bombas.addEdge(a-1,b-1);
	}
	
	
	printf("%d\n",bombas.DFS());
	
		
	
	

 
    return 0;
	
}
