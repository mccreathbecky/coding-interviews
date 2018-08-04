#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target);

int main(){
    int sampleNums[] = {1,7,3,4};
    int *sampleNumsPt = sampleNums;
    int numsSize = 4;
    int target = 12;


    int *returnIndices = twoSum(sampleNumsPt, numsSize, target);

	if (returnIndices[0] == 0 && returnIndices[1] == 0)
	{
		printf("\nNo match found");
		return -1;
	}

    printf("\nsampleNums[0]: %d, sampleNums[1]: %d", sampleNums[returnIndices[0]], sampleNums[returnIndices[1]]);
    free(returnIndices);
    
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *returnIndices = (int *)malloc(sizeof(int)*2);
	returnIndices[0] = 0;
	returnIndices[1] = 0;

	// Step 1: Check for valid input
	if (target < 0 || numsSize <= 0) {
		return returnIndices;
	}

	// Step 2: Loop through array in a double loop - if inputs added = target then return them to main function
    for(int a = 0; a < numsSize; a++){
		for(int b = a + 1; b < numsSize; b++) {
			if(nums[a] + nums[b] == target){
				printf("\nnums[%d]: %d + nums[%d]: %d = %d", a, nums[a], b, nums[b], target);
				returnIndices[0] = a;
				returnIndices[1] = b;
				return returnIndices;
			}
		}
    }

	// Step 3: If no match found, return 0,0
    return returnIndices;
}

