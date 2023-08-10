#include <iostream>
#include <map>
#include <string>
#include "d_state.h"

using namespace std;

int main()
{
    //declare a map object m with 5 elements but using string as key and string as data value
    map<string, string> m; //I did this using the map header file

    m["Maryland"] = "Salisbury";
    m["New York"] = "New York";
    m["Virginia"] = "Harrisonburg";
    m["Delaware"] = "Felton";
    m["Pennsylvania"] = "Lancaster"; //these elements are inserted into the map this way!

    //create a variable that will hold the value for searching a state
    cout << "Enter the name of a state: " << endl;
    string sname;
    cin >> sname;

    //create an iterator that will be used for the find function in the map header file
    map<string, string>::iterator i;
    //use find in map to assign a value to the iterator
    i = m.find(sname);
    if(i != m.end())
    {
        cout << "The state was found and has a city: " << endl;
        cout << i->second << ", " << i->first << endl;
    }
    else
        cout << "State not found in map or does not have city." << endl;

    return 0;
}