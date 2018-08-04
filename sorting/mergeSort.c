/**
 * Example mergeSort algorithm for C
 * Developed as preparation for a coding interview.
*/
#include <stdio.h>

#define IS_DEBUG 1

void printArray(int arr[], int size);
void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);

int main(){
    int sampleArray[] = {38,27,43,3,9,82,10,1};
    printf("\nBefore mergeSort, your array is...");
    printArray(sampleArray, 8);
    mergeSort(sampleArray,0,7);
    printf("\nAfter mergeSort, your array is...");
    printArray(sampleArray, 8);
    return 0;
}


/**
 * prints an array to the screen
 * @params {int []} arr An array to print out
 *         {int} size The amount of elements in the array
 */
void printArray(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
        if (i != size-1){
            printf(",");
        }
    }
    printf("\n");
}

/**
 * Merges two halves of an array into a sorted array
 * @params {int []} arr An array to merge
 *         {int} left The leftmost index of the array to merge
 *         {int} middle The middle of the array to merge [used to create the subArrays]
 *         {int} right The rightmost index of the array to merge
 */
void merge(int arr[], int left, int middle, int right){

    // create two temporary subarrays for the left and right
    // eg with {27,38,3,43}
    // the subArrays are {27,38}, {3, 43}
    int sizeLeft = middle-left+1;
    int sizeRight = right - middle;
    int *tempLeft = (int *)malloc(sizeof(int) * sizeLeft);
    int *tempRight = (int *)malloc(sizeof(int) * sizeRight);

    // fill the subArrays with data from the original array
    for (int i = 0; i<sizeLeft; i++){
        tempLeft[i] = arr[left + i];
    }
    for (int j = 0; j<sizeRight; j++){
        tempRight[j] = arr[middle + j + 1];
    }

    // move through the left array, comparing the first value to the items of the right array until the right has a smaller value
    // whichever value is smaller, update arr[cnt] to have that value
    int currLeft = 0;
    int currRight = 0;
    int cnt;
    for (cnt = left; currRight < sizeRight, currLeft < sizeLeft; cnt++){
        if(tempLeft[currLeft] < tempRight[currRight]){
            arr[cnt] = tempLeft[currLeft++];
        } else{
            arr[cnt] = tempRight[currRight++];
        }
    }

    // for loop ends once currLeft / currRight hits their max bound. However, one will still have leftover values: fill them now!
    while (currLeft < sizeLeft){
        arr[cnt++] = tempLeft[currLeft++]; 
    }
    while (currRight < sizeRight){
        arr[cnt++] = tempRight[currRight++]; 
    }

    // free up the allocated memory to keep the code clean and efficient
    free(tempLeft);
    free(tempRight);
}

/**
 * Recursively sorts an array by splitting it in half and sorting the halves
 * @params {int []} arr An array to sort
 *         {int} left The leftmost index of the array to sort
 *         {int} right The rightmost index of the array to sort
 */
void mergeSort(int arr[], int left, int right){

    if (left < right){
        // find middle point [int truncation giving it as the 'more right' item in case of odd number eg '3' for 7 items, but arr[3] gives 4 items]
        int middle = (left + right)/2;

        // call mergeSort on first half
        mergeSort(arr, left, middle);

        // call mergeSort on second half
        mergeSort(arr, middle + 1, right);

        // merge two sorted halves
        merge(arr, left, middle, right);
    }
}