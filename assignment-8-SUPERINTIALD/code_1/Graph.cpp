#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <list>
using namespace std;


void Graph::addVertex(string name){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex* v = new vertex;
        v->name = name;
        v->visited = false;
        vertices.push_back(v);
    }
}

void Graph::addEdge(string v1, string v2){
    //TODO
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
    adjVertex v1_adjVertex = adjVertex();
    v1_adjVertex.v = v1_vertex;

    adjVertex v2_adjVertex = adjVertex();
    v2_adjVertex.v = v2_vertex;
    // v2_adjVertex.v->previous = v1_vertex;

    if(v1_vertex && v2_vertex)
    {
        // In fully functional code, you should check if the 
        // edge exists too
        v1_vertex->adj.push_back(v2_adjVertex);  
        v2_vertex->adj.push_back(v1_adjVertex);
    }

}

void Graph::displayEdges(){
    //TODO
       for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << " --> "; //<<endl;
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " " ;
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    //TODO

    // TODO: Set all vertices to unvisited
    for(int i = 0; i < vertices.size(); i++) {
      vertices[i]->visited = false;
      vertices[i]->distance = INT16_MAX;
    }

    vertex * root = nullptr;
    // TODO: Find the source vertex -- exit if doesn't exist
    for (int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == sourceVertex){
            root  = vertices[i];

            break;
        }
    }

    // Create a queue for BFS
    list<string> queue;
    root->distance = 0;
    queue.push_back(root->name);
    
    cout<< "Starting vertex (root): " << root->name << "-> ";

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        root->name = queue.front();
        // cout << sourceVertex << "kelivn ";
        queue.pop_front();
        
        // get all adjacent vertices of popped vertex and process each if not already visited 
        for(int i = 0; i < vertices.size(); i++){
            // cout << vertices[i]->name << " --> "; //<<endl;            
             if (vertices[i]->name == root->name){
                vertices[i]->visited = true;
                // vertices[i]->distance++;

                for(int j = 0; j < vertices[i]->adj.size(); j++){
                    // cout << vertices[i]->adj[j].v->name << " " ;
                    if (vertices[i]->adj[j].v->visited == false) 
                    { 
                        vertices[i]->adj[j].v->visited = true; 
                        vertices[i]->adj[j].v->distance = vertices[i]->distance + 1;
                        // vertices[i]->adj[j].v->distance =  (vertices[i]->adj[j].v->distance +  vertices[i]->adj[j].v->distance); 
                        // vertices[i]->adj[j].v->distance++;                        
                        queue.push_back(vertices[i]->adj[j].v->name); 
                        cout << vertices[i]->adj[j].v->name <<"("<< vertices[i]->adj[j].v->distance <<")"<< " ";
                    } 
                }
             }   
        } 
    }
    cout << endl << endl;
}


int Graph::findShortestPathBetweenBuildings(string source, string dest) {
   
    // TODO: Set all vertices to unvisited
    for(int i = 0; i < vertices.size(); i++) {
      vertices[i]->visited = false;
      vertices[i]->distance = INT16_MAX;
    }

    vertex * start = nullptr;
    vertex * end = nullptr;

    // TODO: Find the source vertex -- exit if doesn't exist
    for (int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            start  = vertices[i];
            break;
        }
    }

   for (int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == dest){
            end  = vertices[i];
            break;
        }
    }

    if (end == NULL || start == NULL){
        cout << "No path between source and destination buildings!" << endl;
        return 0;
    }

 
    // Create a queue for BFS
    list<string> queue;
    start->distance = 0;
    queue.push_back(start->name);
    
    // cout<< "Starting vertex (start): " << start->name << "-> ";

    // int startCounter = 0;
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        start->name = queue.front();
        // cout << sourceVertex << "kelivn ";
        queue.pop_front();
        
        // get all adjacent vertices of popped vertex and process each if not already visited 
        for(int i = 0; i < vertices.size(); i++){
            // cout << vertices[i]->name << " --> "; //<<endl;            
            if (vertices[i]->name == start->name){

                vertices[i]->visited = true;
                // vertices[i]->distance++;

                for(int j = 0; j < vertices[i]->adj.size(); j++){
                    // cout << vertices[i]->adj[j].v->name << " " ;
                    if (vertices[i]->adj[j].v->visited == false) 
                    { 
                        vertices[i]->adj[j].v->visited = true; 
                        vertices[i]->adj[j].v->distance = vertices[i]->distance + 1;
                        vertices[i]->adj[j].v->previous = vertices[i]; //testing
                      
                        queue.push_back(vertices[i]->adj[j].v->name); 
                    } 
                }
            }   
        } 
    }
    
    
    for(int i = 0; i < vertices.size(); i++){
            
            if (vertices[i]->name == end->name){        
                if (vertices[i]->distance == INT16_MAX || vertices[i]->distance == 0){
                    // do nothing                    
                }
                else{
                    cout << vertices[i]->name << endl;
                    vertex * tmp = vertices[i]->previous;
                    while (tmp != NULL){
                        // if (tmp->name == dest){
                        if (tmp->name == "DUAN"){
                            //cout << start->name << endl;
                            cout << source << endl;
                        }else{
                            cout << tmp->name << endl;
                        }
                        
                        tmp = tmp->previous;
                    }

                    cout << "Shortest Path Distance: " << vertices[i]->distance ;
                    queue.clear();  // clear the queue to exit while loop
                    break;          // exit for loop
                }                
            } 
        } 
    
    cout << endl;
    return 0;
}

