/*
* You are given two non-empty linked lists representing two non-negative integers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*
*/

#include <stdio.h>


void pushToList(struct ListNode* head, int value);
void fillTestList(struct ListNode* list, int size);
void printListNode(struct ListNode* list);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode {
	int val;
	struct ListNode *next;
};



// MAIN FUNCTION

int main(){
	struct ListNode* testL1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* testL2 = (struct ListNode*)malloc(sizeof(struct ListNode));	

	fillTestList(testL1,7);
	fillTestList(testL2,1);
	struct ListNode* returnList = addTwoNumbers(testL1, testL2);


	printf("\nThis is testL1: ");
	printListNode(testL1);
	printf("\nThis is testL2: ");
	printListNode(testL2);
	printf("\nThis is returnList");
	printListNode(returnList);

	return 0;
}

/*
*	Randomly generates a series of nodes
*	@param {struct ListNode*} head The starting node of the list
*	@param {int} size The amount of nodes in the list
*/
void fillTestList(struct ListNode* head, int size) {
	struct ListNode* current = head;

	current->val = rand() % 10;
	current->next = NULL;

	for (int i = 0; i<size; i++){
		pushToList(head, rand() % 10);
	}
}

/*
*	Adds a new node with the passed value to an existing list
*	@param {struct ListNode*} head The starting node of the list
*	@param {int} value The value to add to the new node
*/
void pushToList(struct ListNode* head, int value) {
	struct ListNode* current = head;


	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	current->next->val = value;
	current->next->next = NULL;

	return;
}


/*
*	Prints a passed list in format (0->1->2->3->7)
*	@param {struct ListNode*} head The starting node of the list
*/
void printListNode(struct ListNode* list) {
	struct ListNode* currentNode = list->next;
	int cnt = 0; //this is just to prevent infinite loops

	printf("\n(%d", list->val);
	while (currentNode != NULL && cnt < 100) {
		printf("->%d", currentNode->val);
		currentNode = currentNode->next;
		cnt++;
	}
	printf(")\n");
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* currentL1 = l1;
	struct ListNode* currentL2 = l2;
	struct ListNode* returnHead  = (struct ListNode *)malloc(sizeof(struct ListNode));

	int counter = 0;
	int listAdd = 0;
	int isOverflow = 0;
	int l1Add = 0, l2Add = 0;


	// loop through listNodes, adding them to create a new linked list
	while (currentL1 != NULL || currentL2 != NULL){

		// check for null values before adding
		if (currentL1 != NULL) {
			l1Add = currentL1->val;
		} else {
			l1Add = 0;
		}
		if (currentL2 != NULL) {
			l2Add = currentL2->val;
		} else {
			l2Add = 0;
		}

		// add the linkedlist values [removing nulls above] and the carry
		listAdd = l1Add + l2Add + isOverflow;

		// pass on the overflow to the next part of the list using basic arithmetic
		if (listAdd > 9) {
			isOverflow = 1;
		} else {
			isOverflow = 0;
		}

		// update the linkedlist for return
		if (counter == 0) {
			returnHead->val = listAdd % 10;
			returnHead->next = NULL;
			counter++;
		} else {
			pushToList(returnHead, listAdd % 10);
		}

		// move forward l1 and l2 if they're not currently null
		if (currentL1 != NULL) {
			currentL1 = currentL1->next;
		}
		if (currentL2 != NULL) {
			currentL2 = currentL2->next;	
		}
	}

	// if the sum of the two linkedLists is greater than the original length
	if (isOverflow == 1) {
		pushToList(returnHead, 1);
	}

	return returnHead;
}
  