#include <iostream>
#include <time.h> //allows srand and rand functions and time function
#include "int.h" //include the int.h file and the other bst header files
#include "d_random.h"
#include "d_except.h"
#include "d_stree.h"
#include <utility> //for pair class

using namespace std;

int main()
{
    srand(time(0)); //set up for using rand function

    stree<integer> integerTree; //create an stree object of the integer type from the int.h
    //name the tree integerTree as asked in the lab 05 instructions
    int i=0; //make a count variable to prepare for a loop
    //make a loop to generate 10000 random integers in the range of 0 to 6
    while(i<10000)
    {
        int num = rand()%7; //generate the number from 0-6
        //create an stnode object to find the generated node in the tree
        stnode<integer> *nodes = integerTree.findNode(num);
        //if the integer is not already in the tree, insert the node into the tree
        if(nodes == NULL)
            integerTree.insert(num);
        //if it is already in the tree, increase the count of the integer
        else
            nodes->nodeValue.incCount();
        
        i++; //increase the count variable
    }

    //make an stnode object to display the tree values
    stnode<integer> *n;
    cout << "Values in the tree: " << endl;
    for(int j=0; j<7; j++)
    {
        n = integerTree.findNode(j); //find the integers of value j in the tree
        cout << n->nodeValue << endl;
    }

    cout << "The tree is: " << endl;
    integerTree.displayTree(1);
}