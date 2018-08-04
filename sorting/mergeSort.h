/**
 * Header file for mergeSort
*/

/**
 * prints an array to the screen
 * @params {int []} arr An array to print out
 *         {int} size The amount of elements in the array
 */
void printArray(int arr[], int size);

/**
 * Merges two halves of an array into a sorted array
 * @params {int []} arr An array to merge
 *         {int} left The leftmost index of the array to merge
 *         {int} middle The middle of the array to merge [used to create the subArrays]
 *         {int} right The rightmost index of the array to merge
 */
void merge(int arr[], int left, int middle, int right);

/**
 * Recursively sorts an array by splitting it in half and sorting the halves
 * @params {int []} arr An array to sort
 *         {int} left The leftmost index of the array to sort
 *         {int} right The rightmost index of the array to sort
 */
void mergeSort(int arr[], int left, int right);