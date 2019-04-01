#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*冒泡排序*/
void bubbleSort(int *a,int arrlen) {
	bool flag = true;
	for (int i = 0; i < arrlen - 1 && flag; i++) {
		flag = false;
		for (int j = 0;j < arrlen -i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				flag = true;
			}
		}
	}
}

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

/*归并排序*/
void merge(int *a, int start, int mid, int end) {
	int *b = (int *)malloc((end - start + 1) * sizeof(int));
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		} else {
			b[k++] = a[j++];
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= end) {
		b[k++] = a[j++];
	}
	for (i = 0; i < k; i++) {
		a[start + i] = b[i];
	}
	free(b);
}
//递归
void mergeSort(int *a,int left,int right) {
	if (left < right) {
		int mid = (left + right) >> 1;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1,right);
		merge(a, left, mid, right);
	}
}
//非递归
void mergeSort2(int *a,int arrlen) {
	for (int i,s = 1; s < arrlen; s += s) {
		for (i = 0; i <= arrlen - 2 * s;i += 2 * s) {
			//合并大小为s的相邻两段数组
			merge(a, i, i + s - 1, i + 2 * s - 1);
		}
		//若剩余元素为“一组半”继续合并，不足一组则剩余元素不动直接进入下一轮归并
		if (i + s < arrlen) {
			merge(a, i, i + s - 1, arrlen - 1);
		}
	}
}
//自然合并排序


void Swap(const void *a,const void *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
