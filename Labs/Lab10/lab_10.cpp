#include <iostream>
#include <fstream>
#include "d_graph.h"
#include "d_util.h"

using namespace std;

int main()
{
    ifstream data("graphB.dat");
    graph<char> B; //represents graph B
    int numNodes, numEdges;
    char vertex, source, destination; //holds vertex value, source vertex and destination vertex for edge making
    int wt; //holds the weight of the edge

    //read in the vertexes from the dat file
    data >> numNodes;
    for(int i = 0; i < numNodes; i++)
    {
        data >> vertex;
        B.insertVertex(vertex);
    }

    //read in edges and weights from dat file
    data >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        data >> source >> destination >> wt;
        B.insertEdge(source, destination, wt);
    }
    
    //prompt user to provide a vertex name for graph traversal
    cout << "Please enter a vertex: ";
    cin >> vertex;

    //make a set of visited vertices to do bfs
    set<char> bfsTrav = bfs(B, vertex);
    cout << "BFS: ";
    writeContainer(bfsTrav.begin(), bfsTrav.end(), " ");
    cout << endl;

    //create a list and carry out process for dfs
    list<char> rev = {'F', 'E', 'D', 'C', 'B', 'A'};
    dfs(B, rev);
    cout << "DFS: ";
    writeContainer(rev.begin(), rev.end(), " ");
    cout << endl;

    return 0;
}