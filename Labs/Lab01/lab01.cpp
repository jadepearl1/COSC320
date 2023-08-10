#include <iostream>
#include "deSelsort.h"

using namespace std;

int main()
{
    int size = 12;
    int myArray[size] = {10, 59, 83, 100, 21, 13, 7, 64, 2, 77, 19, 22};

    cout << "Array before sort: ";
    for(int i=0; i<size; i++)
        cout << myArray[i] << " ";
    cout << endl;

    cout << "Sorting: " << endl;
    deSelsort(myArray, size);

    cout << "Double-ended selection sort is done!" << endl;

    return 0;
}