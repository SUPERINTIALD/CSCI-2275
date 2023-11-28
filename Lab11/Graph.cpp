#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


/*
Adds an undirected edge to the graph.
@param v1: name of the first edge endpoint
@param v2: name of the second edge endpoint
@return: none
*/
void Graph::addEdge(string v1, string v2){
    // Ensure both vertices exist
    vertex* v1_vertex = nullptr;
    vertex* v2_vertex = nullptr;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == v1) { 
            v1_vertex = vertices[i]; 
        }
        else if(vertices[i]->name == v2) { 
            v2_vertex = vertices[i]; 
        }
    }
    
    // Add edge
    if(v1_vertex && v2_vertex)
    {
        // In fully functional code, you should check if the 
        // edge exists too
        v1_vertex->adj.push_back(v2_vertex);
        v2_vertex->adj.push_back(v1_vertex);
    }
}

/*
Adds a new vertex to the graph if it doesn't exist already.
@param n: name of the new vertex
@return: none
*/
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex* v = new vertex;
        v->name = n;
        v->visited = false;
        vertices.push_back(v);
    }
}

/*
Sets all visited attributes for vertices in the graph to false.
@param: none
@return: none
*/
void Graph::setAllVerticesUnvisited()
{
  for(int i = 0; i < vertices.size(); i++) {
      vertices[i]->visited = false;
  }
}

/*
Prints all vertices in the graph and their neighbors
@param: none
@return: none
*/
void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << ": " <<endl;
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << " --> " << vertices[i]->adj[j]->name << " " << endl;
        }
        cout << endl;
    }

}

// ------------------- SILVER PROBLEM -------------------
/*
Prints every node visited in a depth first traversal starting from 
a given vertex. Conventions: 
  1) add neighbors to the stack in the order that the edge was added 
     to the graph (i.e. when you pop the stack, the most recently added
     edge for a node should come off)
  2) mark nodes as 'visited' once printed

@param sourceVertex: the vertex to start the DFT at 
@return: none
*/
void Graph::depthFirstTraversal(string sourceVertex)
{
    // TODO: Set all vertices to unvisited
    setAllVerticesUnvisited();
    vertex* v;
   
    // TODO: Find the source vertex -- exit if doesn't exist
    if(v->name != sourceVertex){
        exit;
    }else{
        v->name = sourceVertex;
        v->visited = true;
    }
    // ~~~ Use a stack to implement DFS ~~~
    vector<vertex*> stack;
    
    // TODO: start the stack with the source vertex
    while(stack.size())
    {
        // TODO: pop from the stack
        vertices.pop_back();
        // TODO: is the popped value visited?
        if(v->visited = false){
            depthFirstTraversal(sourceVertex);
        }else{
            cout << v->name << endl;
            v->visited = true;
        }
        // --> if yes, move on to the next loop iteration
        // --> if not, print and mark as visited
        
        // TODO: add unvisited neighbors to stack
        if(v->visited = false){
            // vertices.push_back(sourceVertex);
        }
        // --> see "Conventions" above
    }
    cout << endl;
}

// ------------------- GOLD PROBLEM -------------------
/*
Verify that the graph is connected. Some notes:
  1) The algorithm for strongly connected graphs as given in class 
     is for directed graphs -- given that our graph is undirected, 
     do we have to do a DFT on every node?)
  2) It is okay if your function prints some output to the console.

@param: none
@return: bool, true if the graph is connected, false otherwise
*/
bool Graph::isConnected()
{
    return true;
}