/*Write a program that generates a list of N random integers in the range [1, 1000], where N
is provided by the user at run time. Then, perform the following tasks:
(a) Ask the user to choose a sorting algorithm from the following:
• Bubble Sort
• Selection Sort
• Insertion Sort
• Merge Sort
(b) Sort the randomly generated numbers using the chosen algorithm.
(c) Print the numbers before and after sorting.
(d) Display the total number of comparisons and swaps (if applicable) performed by the
chosen algorithm.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int comparisons = 0;
int swaps = 0;

//swapping
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    swaps++;
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}

// Selection Sort 
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(&a[i], &a[min]);
    }
}

// Insertion Sort 
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (a[j] > key) {
                a[j + 1] = a[j];
                swaps++;
                j--;
            } else
                break;
        }
        a[j + 1] = key;
    }
}

// Merge function
void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
        swaps++;
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

// Merge Sort
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}


void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 + 1;

    printf("\nUnsorted Array:\n");
    printArray(a, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    comparisons = swaps = 0;

    switch (choice) {
        case 1: bubbleSort(a, n); break;
        case 2: selectionSort(a, n); break;
        case 3: insertionSort(a, n); break;
        case 4: mergeSort(a, 0, n - 1); break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("\nSorted Array:\n");
    printArray(a, n);

    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Total Swaps/Moves: %d\n", swaps);

    return 0;
}
