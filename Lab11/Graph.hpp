#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct vertex {
    string name;
    bool visited;
    vector<vertex*> adj;
};

class Graph
{
    public:
        void addEdge(string v1, string v2);
        void addVertex(string name);
        void displayEdges();
        void setAllVerticesUnvisited();
        void depthFirstTraversal(string sourceVertex);
        bool isConnected();

    private:
        vector<vertex*> vertices;
};

#endif // GRAPH_H
