#include <iostream>
#include "d_tnode.h"

void prefixoutput(tnode<char> *root)
{
    if(root != nullptr)
    {
        cout << root->nodeValueStr << " ";

        prefixoutput(root->left);
        prefixoutput(root->right);
    }
}