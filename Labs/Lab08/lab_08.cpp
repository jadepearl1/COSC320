#include <iostream>
#include "preqrec.h"
#include "d_pqueue.h"
#include "d_heap.h"
#include "d_except.h"
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));

    miniPQ<procReqRec, less<procReqRec>> mpq;

    mpq.push(procReqRec("Process A", rand()% 40));
    mpq.push(procReqRec("Process B", rand()% 40));
    mpq.push(procReqRec("Process C", rand()% 40));
    mpq.push(procReqRec("Process D", rand()% 40));
    mpq.push(procReqRec("Process E", rand()% 40));
    mpq.push(procReqRec("Process F", rand()% 40));
    mpq.push(procReqRec("Process G", rand()% 40));
    mpq.push(procReqRec("Process H", rand()% 40));
    mpq.push(procReqRec("Process I", rand()% 40));
    mpq.push(procReqRec("Process J", rand()% 40));

    for(int i=0; i<10; i++)
    {
        cout << mpq.top();
        mpq.pop();
    }
}
