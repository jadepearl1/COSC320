#include "d_tnode.h"
#include "d_tnode1.h"
#include <iostream>

using namespace std;

void countOneChild(tnode<char> *root, int& count)
{
    //if a node has only one side, then it has a child so the count increments
    if (root != NULL){
        if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
            count++;

        countOneChild(root->left, count);
        countOneChild(root->right, count);
    }
}