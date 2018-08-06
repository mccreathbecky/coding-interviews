/**
 * My first binary search algorithm
*/

#include <stdio.h>
#include <stdbool.h>

#define ISDEBUG 1

bool binarySearchRecursive(int arr[], int key, int left, int right){
    if (left > right){
        return false;
    }

    int mid = left + (right-left)/2;
    if(ISDEBUG) printf("\nLeft: %d, Right: %d, Mid is: %d", left, right, mid);

    if(arr[mid] == key){
        if(ISDEBUG) printf("\n%d is in array!",key);
        return true;
    } else if (arr[mid] > key){
        return binarySearchRecursive(arr, key, left, mid - 1);
    } else {
        return binarySearchRecursive(arr, key, mid + 1, right);
    }
    return false;
}


int main(void){
    int sampleArray[] = {1,2,7,11,14,22,79,103};
    bool inArray = false;

    if(ISDEBUG) printf("\nIs 7 in array?");
    inArray = binarySearchRecursive(sampleArray, 7, 0, 7);
    if(!inArray)
        if(ISDEBUG) printf("\nSadly, no.");

    if(ISDEBUG) printf("\nIs 150 in array?");
    inArray = binarySearchRecursive(sampleArray, 150, 0, 7);
    if(!inArray)
        if(ISDEBUG) printf("\nSadly, no.");

    return 0;
}