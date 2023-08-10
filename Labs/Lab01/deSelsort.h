#include <iostream>
using namespace std;

void deSelsort(int *arr, int n)
{
    //double ended selection sort implementation
    for(int i=0, j=n-1; i<j; i++, j--)
    {
        int minVal = arr[i];
        int maxVal = arr[i];
        int minInd = i;
        int maxInd = i;
        for(int k=i; k<=j; k++)
        {
            if(arr[k]>maxVal){
                maxVal=arr[k];
                maxInd=k;
            }
            else if(arr[k]<minVal){
                minVal=arr[k];
                minInd=k;
            }
        }
        swap(arr[i], arr[minInd]);
        if(arr[minInd]==maxVal)
            swap(arr[j], arr[minInd]);
        else
            swap(arr[j], arr[maxInd]);

        for(int l=0; l<n; l++)
            cout << arr[l] << " ";
        cout << endl;
    }
}