#include <stdio.h>
#include <stdlib.h>

void xorswap(int *a, int *b){
    if ( *a != *b){
    *a ^ *b = *a;
    *a ^ *b = *b;
    *a ^ *b = *a;
    }
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble(int* a, int n){
    int flag = 0;
    for (int i = 0; i < n - 1; ++i){
            flag = 0;
        for (int j = 0; j < n - 1-i; ++j ){
            if (a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void merge(int A[ ], int l, int m, int r){
    int i = l, j = m + 1, k = l;
    int B[100];
    while(i <= m && j <=r ){
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= m; i++)
        B[k++] = A[i];
    for (; j<=r; j++)
        B[k++] = A[j];

    for (int i = l; i <=r; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[ ], int l, int r){
    int m = l + (r - l)/2;
    if (l < r){
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, m, r);
    }
}
int partition(int A[], int l, int r){
    int pivot = A[l];
    int i = l, j = r;
    do {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);

        if (i < j) swap(&A[i], &A[j]);
    }while(i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quicksort(int A[], int l, int r){
    int j;
    if (l < r){
        j = partition(A, l, r);
        quicksort(A, l, j);
        quicksort(A,j+1,r);
    }
}
int main()
{
    int a[10] = {3,2,1};
    //bubble(a, 3);
    mergeSort(a,0, 2);
    //quicksort(a, 0, 3);
    for (int i = 0; i < 3; i++)
        printf("%d\n",a[i]);
    return 0;
}
