#include <iostream>
#include "d_tnode1.h"
#include "inf2pstf.h"
#include <stack>
#include <string>
#include <ctype.h>

//This code contains the function buildExpTree which is already written code and not my work
//as directed by the lab instructions, I copied the implementation of the function into this code

using namespace std;

// build an expression tree from a postfix expression.
// the operands are single letter identifiers in the range from
// 'a' .. 'z' and the operators are selected from the characters
// '+', '-', '*' and '/'
tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}

void prefixoutput(tnode<char> *root)
{
    if(root != nullptr)
    {
        cout << root->nodeValue << " ";

        prefixoutput(root->left);
        prefixoutput(root->right);
    }
}

int main()
{
    tnode<char> *binExpTree; //define a variable for the tree
    int maxChars = 50;
    string exp; //define the variable that will hold the infix expression
    cout << "Enter an infix expression for building a binary expression tree: " << endl;
    cin >> exp;

    infix2Postfix pstfx(exp);
    exp = pstfx.postfix();
    cout << "Sending the expression for tree building..." << endl;
    binExpTree = buildExpTree(exp);
    cout << "Prefix form: ";
    prefixoutput(binExpTree);
    cout << endl;
    cout << "Postfix form: ";
    postorderOutput(binExpTree);
    cout << endl;
    cout << "Here is the tree: ";
    displayTree(binExpTree, maxChars);

    return 0;
}
