// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include<iostream>
#include<list>
#include<stdio.h>
using namespace std;

 
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
    
	int cantComp;

	
	void clear();
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    cantComp = 0;
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
    visited[v] = true;
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to print DFS traversal
    for (int i = 0; i < V; i++)
        if (visited[i] == false){
        	DFSUtil(i, visited);
        	cantComp++;
		}
}



int main()
{
	int t;
	scanf("%d",&t);
	
	for(int i = 0; i < t; i++){
		
		int N, e;
		
		scanf("%d",&N);
		scanf("%d",&e);
		
		Graph personas(N);
		
		int a;
		int b;
		
		
		for(int j = 0; j < e; j++){
		
			scanf("%d",&a);
			scanf("%d",&b);
			
			personas.addEdge(a,b);
			personas.addEdge(b,a);
		}
		
		personas.DFS();
		
		printf("%d\n",personas.cantComp);
		
		
	}
	

 
    return 0;
}
