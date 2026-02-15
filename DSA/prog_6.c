/*Given the array of the data (unsorted), Write a program to build the min and max heap.*/

#include <stdio.h>

//Swapping
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Min heap
void minHeap(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeap(arr, n, smallest);  //Recursion function used
    }
}


void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeap(arr, n, i);
}

//Max Heap
void maxHeap(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);  //Recursion function used
    }
}


void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);
}


void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);  //defining number of terms in array

    int minHeap[10], maxHeap[10];

    for (int i = 0; i < n; i++) {
        minHeap[i] = arr[i];
        maxHeap[i] = arr[i];
    }

    buildMinHeap(minHeap, n);
    buildMaxHeap(maxHeap, n);

    printf("Min Heap: ");
    display(minHeap, n);

    printf("Max Heap: ");
    display(maxHeap, n);

    return 0;
}
