#include <iostream>

using namespace std;

int binSearch(int arr[], int size, int target, int& fails, int& sucs, int& totalSucs)
{
    int first = 0, last = size - 1;
    int comparisons = 0;
    while (first <= last) {
        int mid = first + (last - first) / 2;
        comparisons++;
        if (arr[mid] == target) {
            sucs += comparisons;
            totalSucs++;
            return mid;
        } else if (arr[mid] < target) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    fails += comparisons; //if failed, increment number of comparisons in unsuccessful search
    return -1; // return -1 if x not found
}