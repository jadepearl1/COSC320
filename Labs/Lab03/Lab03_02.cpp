#include "max.h"
#include <iostream>
#include "d_tnode.h"
#include "d_tnode1.h"

using namespace std;

tnode<int> *buildIntTree()
{
    //define the nodes of children
    tnode<int> *twelve = new tnode<int> (12);
    tnode<int> *fortyEight = new tnode<int> (48);
    tnode<int> *five = new tnode<int> (5);

    //define parent nodes that are not the root
    tnode<int> *fifteen = new tnode<int> (15, fortyEight, twelve);
    tnode<int> *forty = new tnode<int> (40, five, (tnode<int> *)NULL);

    //define the root and it's children
    tnode<int> *root = new tnode<int> (35, forty, fifteen);
    return root;
}

int main()
{
    tnode<int> *binTree;
    binTree = buildIntTree();
    int maxVal = binTree->nodeValue;

    max(binTree, maxVal);

    cout << "The maximum value found in the binary tree is: " << maxVal << endl;
    return 0;
}