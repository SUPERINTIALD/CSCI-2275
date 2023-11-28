#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;    
int main()
{
    Graph g1;
    g1.addVertex("Aurora");
    g1.addVertex("Bloomington");
    g1.addVertex("Cheyenne");
    g1.addVertex("Denver");
    g1.addVertex("Fruita");
   
    g1.addEdge("Aurora", "Bloomington");
    g1.addEdge("Aurora", "Cheyenne");
    g1.addEdge("Aurora", "Fruita");
    g1.addEdge("Cheyenne", "Denver");
    g1.addEdge("Denver", "Bloomington");
    g1.addEdge("Bloomington", "Fruita");
    
    cout << "===== Silver Problem: DFS =====" << endl;
    
    cout << "> Test 1" << endl;
    cout << "  Expected: Aurora Fruita Bloomington Denver Cheyenne" << endl;
    cout << "  Got:      ";
    g1.depthFirstTraversal("Aurora");
    
    cout << "> Test 2" << endl;
    cout << "  Expected: Bloomington Fruita Aurora Cheyenne Denver" << endl;
    cout << "  Got:      ";
    g1.depthFirstTraversal("Bloomington");
    
    cout << "> Test 3" << endl;
    cout << "  Expected: Cheyenne Denver Bloomington Fruita Aurora" << endl;
    cout << "  Got:      ";
    g1.depthFirstTraversal("Cheyenne");
    
    cout << "> Test 4" << endl;
    cout << "  Expected: Denver Bloomington Fruita Aurora Cheyenne" << endl;
    cout << "  Got:      ";
    g1.depthFirstTraversal("Denver");
    
    cout << "> Test 5" << endl;
    cout << "  Expected: Fruita Bloomington Denver Cheyenne Aurora" << endl;
    cout << "  Got:      ";
    g1.depthFirstTraversal("Fruita");
    
    cout << "===== Gold Problem: DFS =====" << endl;
    bool val;
    cout << "> Test 1" << endl;
    val = g1.isConnected();
    cout << "  Expected: 1" << endl;
    cout << "  Got:      " << val << endl;
    
    Graph g2;
    g2.addVertex("Aurora");
    g2.addVertex("Bloomington");
    cout << "> Test 2" << endl;
    val = g2.isConnected();
    cout << "  Expected: 0" << endl;
    cout << "  Got:      " << val << endl;
    
    Graph g3;
    g3.addVertex("Aurora");
    g3.addVertex("Bloomington");
    g3.addVertex("Cheyenne");
    g3.addVertex("Denver");
    g3.addVertex("Fruita");
    g3.addEdge("Aurora", "Bloomington");
    g3.addEdge("Aurora", "Fruita");
    g3.addEdge("Cheyenne", "Denver");
    cout << "> Test 3" << endl;
    val = g3.isConnected();
    cout << "  Expected: 0" << endl;
    cout << "  Got:      " << val << endl;
}
   