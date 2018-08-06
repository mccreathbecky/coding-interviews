/**
 *  Binary Search Recursive and Iterative Implementations 
 */


/**
 * Uses a Recursive Binary Search to try and locate a number in a sorted array
 * @params {int []} arr A sorted array to search within
 *          {int} key The value to search for
 *          {int} size The size of the array
 * @returns {bool} True if the key was found
 */
bool binarySearchRecursive(int arr[], int key, int left, int right);


/**
 * Uses an Iterative Binary Search to try and locate a number in a sorted array
 * @params {int []} arr A sorted array to search within
 *          {int} key The value to search for
 *          {int} size The size of the array
 * @returns {bool} True if the key was found
 */
bool binarySearchIterative(int arr[], int key, int size);