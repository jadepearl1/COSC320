#include <iostream>
#include <cstdlib>
#include <ctime>
#include "binSearch.h"
#include "deSelsort.h"

using namespace std;

int main(){
    int ARRSIZE = 10000;
    int RANDOMLIMIT = 99999;
    int RANDOMVALUES = 10000;

    int sumFailCom = 0;
    int sumSucCom = 0;
    int successTotal = 0;

    int myArray [ARRSIZE];
    srand(time(0));

    for(int i=0; i<ARRSIZE; i++)
    {
        myArray[i] = rand()%RANDOMLIMIT;
    }

    deSelsort(myArray, ARRSIZE);

    for(int i=0; i<RANDOMVALUES; i++)
    {
        int target = rand()%RANDOMLIMIT;
        binSearch(myArray, ARRSIZE, target, sumFailCom, sumSucCom, successTotal);
    }

    cout << "There were " << successTotal << " successful searches." << endl;
    cout << "There were " << sumFailCom << " comparisons in the unsuccessful searches." << endl;
    cout << "There were " << sumSucCom << " comparisons in the successful searches." << endl;
    cout << "The empirical result for worst-case comparison used for an unsuccessful search is: "
         << sumFailCom/(RANDOMVALUES-successTotal) << endl;
    cout << "The empirical result for worst-case comparison used for successful searches is: "
         << sumSucCom/successTotal << endl;

    cout << "Thank you!!" << endl;

    return 0;
}