#include <iostream>
#include <fstream>
#include <string>
#include "d_except.h"
#include "d_hash.h"
#include "d_hashf.h"

using namespace std;

//extract a word from fin
ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}

int main()
{
    //open the input file that holds all the 25025 words to put in a hash table
    ifstream dictionary;
    dictionary.open ("dict.dat");

    int numBuckets = 1373; //make a variable that stores the number of buckets in the hash table
    //make a hash object with type string using the hFstring class and create the hash table
    //using the myhash class object from d_hash.h
    myhash<string, hFstring> hsh(numBuckets);
    if(dictionary.is_open())
    {
        string word;
        //add each word from dict.dat into the hash table. increments until the end of the dictionary file is reached
        for(int i = 0; !dictionary.eof(); i++)
        {
            dictionary >> word;
            hsh.insert(word);
        }
    }
    else
        cout << "File not found or cannot be opened!" << endl;

    string input; //holds the name of the document that the user will have the program evaluate for spelling
    cout << "Please enter the name of a document you would like to check for spelling errors. " 
         << "Please include file type (i.e. txt, doc, etc): " << endl;
    cin >> input;

    ifstream in; //file that the user will be opening
    in.open(input); //open the file

    string check; //holds the value of the word that is to be checked for spelling
    if(in.is_open())
    {
        cout << "Misspelled Words: " << endl << endl;
        while(in) //reads the file while it is not at the end
        {
            getWord(in, check); //use getWord function that was provided
            //getWord also converts uppercase to lowercase letters for the hash table to check spelling
            //if the word is not found, then the word is displayed on screen
            if(hsh.end() == hsh.find(check))
                cout << check << endl;
        }
    }
    else
        cout << "File cannot be open or is not found." << endl;

    dictionary.close();
    in.close();

    return 0;
}
