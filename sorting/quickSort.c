/**
 * Example quickSort algorithm for C
 * Developed as preparation for a coding interview.
 * Based on https://www.youtube.com/watch?v=SLauY6PpjW4
 * and https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_program_in_c.htm
 */
#include <stdio.h>
#define IS_DEBUG 1

void printArray(int arr[], int size, int start);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int* a, int* b);

int main(void){
    int sampleArray[] = {15,3,2,1,9,5,7,8,6};

    quickSort(sampleArray,0,8);

    printf("\nquickSort is...");
    printArray(sampleArray,9,0);

    return 0;
}

/**
 * prints an array to the screen, from the specified start position to the finish position
 * @params {int []} arr An array to print out
 *         {int} start The first index to print out
 *         {int} finish The final index to print out
 */
void printArray(int arr[], int start, int finish){
    printf("\n");
    for(int i = start; i < finish; i++){
        printf("%d", arr[i]);
        if (i != finish-1){
            printf(",");
        }
    }
    printf("\n");
}

/**
 * Swap two integers with an existing space in memory, e.g. in an array
 * @params {int *} a A pointer to the first integer to swap (likely &arr[m])
 *         {int *} b A pointer to the second integer to swap (likely &arr[n])
 */
void swapInts(int* a, int* b){
    printf("\nNow swapping: %d, %d", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * prints an array to the screen, from the specified start position to the finish position
 * @params {int []} arr An array to print out
 *         {int} start The first index to print out
 *         {int} finish The final index to print out
 */
int partition(int arr[], int left, int right){
    int leftPointer = left;
    int rightPointer = right;
    int swap = 0;

    // determine pivot point
    // create a pivot point [could be random, we'll take a mid point]
    int pivotIndex = left+(right-left)/2;
    int pivotValue = arr[pivotIndex];
    if(IS_DEBUG) printf("\nPivot around: %d", pivotValue);

    // {1,2,6,*4*,3,5,9}   where *4* is pivot
    // move pointers in towards each other
    while (leftPointer <= rightPointer){
        // move left pointer until an element is greater than the pivot OR it's exceeded the pivot bounds
        while(arr[leftPointer] < pivotValue) {
            leftPointer++; 
        }
        while(arr[rightPointer] > pivotValue){
            rightPointer--; 
        }

        // if left < right, swap them around
        if(leftPointer <= rightPointer){
            // swap around the values
            swapInts(&arr[leftPointer], &arr[rightPointer]);

            // move the pointers
            leftPointer++;
            rightPointer--;
        }
    }

    if(IS_DEBUG) printf("\nArray after partition: ");
    if(IS_DEBUG) printArray(arr,right+1,left);

    // return partition dividing point [where left is];
    return leftPointer;
}

void quickSort(int arr[], int left, int right){
    if (left < right){
        if(IS_DEBUG) printf("\nArray to be sorted: ");
        if(IS_DEBUG) printArray(arr,right+1,left);

        int index = partition(arr, left, right);

        // call quicksort on the left
        quickSort(arr, left, index-1);
        
        // call quicksort on the right
        quickSort(arr, index, right);
    }
}