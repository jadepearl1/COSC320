#include "d_tnode.h"
#include "d_tnode1.h"
#include <iostream>

using namespace std;

void max(tnode<int> *root, int& maxVal)
{
    //if the root exists, find the max value in the tree
    if(root != NULL)
    {
        if (maxVal < root->nodeValue)
            maxVal = root->nodeValue;

        max(root->left, maxVal);
        max(root->right, maxVal);
    }
}