#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*直接插入排序*/
void StrInsert(int arr[],int arrlen)
{
    int i,j,sentry;
    for(i = 1;i < arrlen;i++)
        if(arr[i] < arr [i-1])
        {
            sentry = arr[i];
            for(j = i-1;j >= 0 && sentry < arr[j];j--)
                arr[j+1] = arr[j];
                arr[j+1] = sentry;
        }
}

/*选择排序*/
void SelectSort(int arr[],int arrlen)
{
    int i,j,minindex;
    for(i = 0;i < arrlen;i++)
    {
        minindex = i;
        for(j = i+1;j < arrlen;j++)
        {
            if(arr[j] < arr[minindex])
                minindex = j;
        }
        if(minindex != i)
            Swap(&arr[i],&arr[minindex]);
    }
}

/*希尔排序*/
void ShellSort(int arr[],int arrlen)
{
    int i,j,gap;
    for(gap = arrlen/2;gap > 0;gap /= 2)
        for(i = gap;i < arrlen;i++)
            for(j = i-gap;j >= 0 && arr[j] > arr[j+gap];j -= gap)
                Swap(&arr[j],&arr[j+gap]);
}

/*快速排序*/
void QuickSort(int arr[],int left,int right)
{
    if(left < right)
    {
        int i,j,index;
        i = left;
        j = right;
        index = arr[i];
        while(i <j)
        {
            while(i < j && arr[j] > index)
                j--;
            if(i < j)
                arr[i++] = arr[j];
            while(i < j && arr[i] < index)
                i++;
            if(i > j)
                arr[j--] = arr[i];
        }
        arr[i] = index;
        QuickSort(arr,left,i-1);
        QuickSort(arr,i+1,right);
    }
}

void Swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
