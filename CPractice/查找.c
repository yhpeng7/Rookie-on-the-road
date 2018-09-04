#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*二分查找*/
int binarySearch(int arr[],int arrlen,int key)
{
    int low = 0;
    int high = arrlen -1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}