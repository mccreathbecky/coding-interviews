/**
 * My first binary search algorithm
*/

#include <stdio.h>
#include <stdbool.h>
#include "binarySearch.h"

#define ISDEBUG 1


/**
 * Uses a Recursive Binary Search to try and locate a number in a sorted array
 * @params {int []} arr A sorted array to search within
 *          {int} key The value to search for
 *          {int} size The size of the array
 * @returns {bool} True if the key was found
 */
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


/**
 * Uses an Iterative Binary Search to try and locate a number in a sorted array
 * @params {int []} arr A sorted array to search within
 *          {int} key The value to search for
 *          {int} size The size of the array
 * @returns {bool} True if the key was found
 */
bool binarySearchIterative(int arr[], int key, int size){
    if (size < 1){
        return false;
    }

    int left = 0;
    int right = size-1;
    int mid = left + (right-left)/2;

    while (left <= right){

        mid = left + (right-left)/2;
        if(ISDEBUG) printf("\nLeft: %d, Right: %d, Mid is: %d", left, right, mid);

        if(arr[mid] == key){
            if(ISDEBUG) printf("\n%d is in array!",key);
            return true;
        } else if (arr[mid] > key){
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }

    return false;
}


int main(void){
    int sampleArray[] = {1,2,7,11,14,22,79,103};
    bool inArray = false;

    if(ISDEBUG) printf("\nIs 7 in array?");
    inArray = binarySearchIterative(sampleArray, 7, 8);
    if(!inArray)
        if(ISDEBUG) printf("\nSadly, no.");

    if(ISDEBUG) printf("\nIs 150 in array?");
    inArray = binarySearchIterative(sampleArray, 150, 8);
    if(!inArray)
        if(ISDEBUG) printf("\nSadly, no.");

    return 0;
}