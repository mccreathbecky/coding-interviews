/**
 * Header file for quickSort.c
*/


/**
 * prints an array to the screen, from the specified start position to the finish position
 * @params {int []} arr An array to print out
 *         {int} start The first index to print out
 *         {int} finish The final index to print out
 */
void printArray(int arr[], int start, int finish);

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
int partition(int arr[], int left, int right);

/**
 * Recursively sorts an array by splitting it into sections around a pivot until all elements are in order
 * @params {int []} arr An array to sort
 *         {int} left The leftmost index of the array to sort
 *         {int} right The rightmost index of the array to sort
 */
void quickSort(int arr[], int left, int right);

