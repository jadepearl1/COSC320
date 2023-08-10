#include <iostream>
#include <set>
#include <string>
#include "d_state.h"

using namespace std;

int main()
{
    //declare a set object s having 5 elements of type stateCity from d_state.h
    set<stateCity> s; //I did this using the set header file.

    stateCity city1("Maryland", "Salisbury");
    stateCity city2("New York", "New York");
    stateCity city3("Virginia", "Harrisonburg");
    stateCity city4("Delaware", "Felton");
    stateCity city5("Pennsylvania", "Lancaster");

    //insert the 5 stateCity elements into the set!
    s.insert(city1);
    s.insert(city2);
    s.insert(city3);
    s.insert(city4);
    s.insert(city5);

    //create a variable that will hold the value for searching a state
    cout << "Enter the name of a state: " << endl;
    string sname;
    cin >> sname;

    //create an iterator that will be used for the find function in the set header file
    set<stateCity>::iterator i;

    //define a boolean that will hold if the searched element is found or not
    bool found = false;

    //make a loop to iterate through the string to see if the state is present
    for(i = s.begin(); i != s.end(); ++i)
    {
        if(i->stateName == sname)
        {
            cout << "The state was found in the set and has a city: " << endl;
            cout << *i << endl;
            found = true;
        }
    }

    //output the proper message if the state is not found in the set
    if(!found)
    {
        cout << "State not found in set or state has no city name." << endl;
    }

    return 0;
}
