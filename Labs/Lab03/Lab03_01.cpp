#include <iostream>
#include "countOneChild.h"
#include "d_tnode.h"
#include "d_tnode1.h"

using namespace std;

int main()
{
    //keeps track of the number of nodes with one child
    int count = 0;

	// 9 tnode pointers; points to the 9 items in the tree
    //defines the leaves of the tree (no children)
    tnode<char> *d = new tnode<char> ('D');
    tnode<char> *f = new tnode<char> ('F');
    tnode<char> *g = new tnode<char> ('G');

    //define the parent nodes
    tnode<char> *b = new tnode<char> ('B', d, (tnode<char> *)NULL);
    tnode<char> *e = new tnode<char> ('E', (tnode<char> *)NULL, g);
    tnode<char> *c = new tnode<char> ('C', e, f);

    //lastly, define the root and it's children
    tnode<char> *root = new tnode<char> ('A', b, c);
    
    countOneChild(root, count);
    cout << "The count for nodes with one child in this tree is: " << count << endl;

    return 0;
}