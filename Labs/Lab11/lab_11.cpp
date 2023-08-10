#include <iostream>
#include <fstream>
#include <set>
#include <queue>
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

    data.close();

    //prompt user to provide a vertex name from graph B
    cout << "Please enter a vertex from graph B: ";
    cin >> vertex;

    list<char> path;
    int min = 0;
    char vert2, maxVert;
    data.open("graphB.dat");
    data >> numNodes;
    while(numNodes!=0)
    {
        data >> vert2;
        if(minimumPath(B, vert2, vertex, path) > min){
            min = minimumPath(B, vert2, vertex, path);
            maxVert = vert2;
        }
        numNodes--;
    }

    minimumPath(B, maxVert, vertex, path);
    //for each other vertex in the graph, determine weight of the minimum path weight
    //output the vertex w/ largest minimum-path weight, weight of minimum path, and the path itself
    cout << "Vertex with largest minimum path value: " << maxVert << endl;
    cout << "Minimum path value: " << min << endl;
    cout << "Minimum path: ";
    writeContainer(path.begin(), path.end(), " ");
    cout << endl;
    data.close();
    

    return 0;
}