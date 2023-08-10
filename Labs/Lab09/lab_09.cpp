#include <iostream>
#include <fstream>
#include <set> //for use of the getNeighbors function
#include "d_graph.h"

using namespace std;

int main()
{
    //declare a graph A and int variables for vertices and edges
    graph<char> a;
    int numNodes, numEdges;
    char vertex, source, destination; //holds vertex value, source vertex and destination vertex for edge making
    int wt; //holds the weight of the edge

    ifstream data; //input stream for the input data file
    data.open("graphA.dat"); //open the file

    //use a loop to fill the graph using the input file
    data >> numNodes; //extracts the number of nodes from the data file
    for(int i = 0; i < numNodes; i++)
    {
        data >> vertex;
        a.insertVertex(vertex);
    }
    data >> numEdges; //extracts the number of edges from the data file
    for(int i = 0; i < numEdges; i++)
    {
        data >> source >> destination >> wt;
        a.insertEdge(source, destination, wt);
    }

    //insert edge from F to D with weight 1
    a.insertEdge('F', 'D', 1);
    //delete vertex B
    a.eraseVertex('B');
    //erase edge from A to D
    a.eraseEdge('A', 'D');
    //Prompt user to input a vertex and list all neighbors of the vertex
    cout << "Please input a vertex: " << endl;
    cin >> vertex;
    set<char> neighbors;
    neighbors = a.getNeighbors(vertex);
    set<char>::iterator iter = neighbors.begin();
    cout << "Here are the neighbors of the given vertex: ";
    //traverse the set of neighbors and print them using set iterator
    while(iter != neighbors.end())
    {
        cout << *iter << " ";
        *iter++;
    }
    cout << endl;
    //insert new vertex G
    a.insertVertex('G');
    //add following edges with weight 1: G-C G-F D-G
    a.insertEdge('G', 'C', 1);
    a.insertEdge('G', 'F', 1);
    a.insertEdge('D', 'G', 1);
    //Output graph using <<
    cout << "Here is the graph!" << endl;
    cout << a;

    return 0;
}