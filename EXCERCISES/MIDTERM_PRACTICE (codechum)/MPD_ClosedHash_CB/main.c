#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write your functions here
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(char *arr[], int n, int i) {
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && strcmp(arr[left], arr[root]) > 0)
        root = left;
    
    if(right < n && strcmp(arr[right], arr[root]) > 0)
        root = right;
        
    if(root != i) {
        swap(&arr[i], &arr[root]);
        heapify(arr, n, root);
    }
}

void heapSort(char *arr[], int n) {
    for (int i = n/2 - 1; i>=0; i--)
        heapify(arr, n, i);

    for (int i = n- 1; i>0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}