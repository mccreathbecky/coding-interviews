/**
 * Example quickSort algorithm for C
 * Developed as preparation for a coding interview.
 * Based on https://www.youtube.com/watch?v=SLauY6PpjW4
 * and https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_program_in_c.htm
 */
#include <stdio.h>
#define IS_DEBUG 1

void printArray(int arr[], int start, int finish);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int* a, int* b);

int main(void){
    int sampleArray[] = {15,3,2,1,9,5,7,8,6};
    printf("\nbefore quickSort your array is...");
    printArray(sampleArray,0,8);

    quickSort(sampleArray,0,8);

    printf("\n\nAfter quickSort your array is...");
    printArray(sampleArray,0,9);

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
 * Sorts an array into two sections, one that's smaller than a generated 'pivot' on the left, and one that's greater than or equal to the pivot on the right
 * @params {int []} arr An array to partition
 *         {int} left The leftmost index of the array to partition
 *         {int} right The rightmost index of the array to partition
 * @return {int} the dividing index of the partition, which is the final value of the leftPointer
 * @example
 *      if you had an exampleArray {15,3,2,1,9,5,7,8,6}
 *      and called partition(exampleArray, 0, 8) in quickSort;
 *      the pivot would be around arr[4]: 9
 *      this would sort exampleArray to have {6,3,2,1,8,5,7|9,15}
 *      and return an index of 7
 */
int partition(int arr[], int left, int right){
    // create a pivot point [it could be random, we'll take a mid point, some equations take the rightmost index]
    int pivotIndex = left+(right-left)/2;   // note you can't just do right/2 as you won't always have the left point as 0
    int pivotValue = arr[pivotIndex];
    if(IS_DEBUG) printf("\nPivot around index[%d]: %d", pivotIndex, pivotValue);

    // These are used to traverse the array when searching for numbers smaller and larger than the pivot
    int leftPointer = left;
    int rightPointer = right;

    // Move through the section of the array defined by the left/right pointers,
    // moving the pointers in towards each other as you go
    while (leftPointer <= rightPointer){

        // move left pointer until an element is greater than or equal to the pivot
        while(arr[leftPointer] < pivotValue) {
            leftPointer++; 
        }
        // move the right pointer to the left until an element is less than the pivot
        while(arr[rightPointer] > pivotValue){
            rightPointer--; 
        }

        // if left index < right index, swap around their values
        if(leftPointer <= rightPointer){
            // swap around the values
            swapInts(&arr[leftPointer], &arr[rightPointer]);

            // move the pointers
            leftPointer++;
            rightPointer--;
        }
    }

    if(IS_DEBUG) printf("\nArray after partition: ");
    if(IS_DEBUG) printArray(arr,left,right+1);
    if(IS_DEBUG) printf("\nindex is: %d", leftPointer);

    // return the partition dividing point [where left is]
    return leftPointer;
}

/**
 * Recursively sorts an array by splitting it into sections around a pivot until all elements are in order
 * @params {int []} arr An array to sort
 *         {int} left The leftmost index of the array to sort
 *         {int} right The rightmost index of the array to sort
 */
void quickSort(int arr[], int left, int right){
    if (left < right){
        if(IS_DEBUG) printf("\nArray to be sorted: ");
        if(IS_DEBUG) printArray(arr,left, right+1);

        int index = partition(arr, left, right);

        // call quicksort on the left
        quickSort(arr, left, index-1);
        
        // call quicksort on the right
        quickSort(arr, index, right);
    }
}