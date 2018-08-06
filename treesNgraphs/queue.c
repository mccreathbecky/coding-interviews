/**
 * Basic queue implementation
*/

#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#define ISDEBUG 1

/**
 * Creates a new node with the passed value
 * @params  {int}       val     The value to add to the new node
 * @return  {node_t*}   The newly created node
*/
node_t* createNode(int val){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->value = val;
    node->next = NULL;
    if(ISDEBUG) printf("\nCreated new node with value: %d", node->value);
    return node;
}

/**
 * Creates a new queue
 * @returns {queue_t*}  A pointer to a new queue
*/
queue_t* createQueue(){
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    queue->size = 0;
    queue->startNode = NULL;
    queue->finishNode = NULL;
    return queue;
}

/**
 * Adds a new node to the end of the queue
 * @params  {queue_t*}  queue   The queue to add to
 *          {int}       val     The value to add to the new node
*/
void add(queue_t* queue, int val){
    // create a new node and make its 'next' value the current final node
    node_t* newNode = createNode(val);

    // if this is the first node created, it will be both start and finish nodes 
    if(queue->size == 0){
        queue->startNode = newNode;
        queue->finishNode = newNode;
        queue->size = 1;
        if(ISDEBUG) printf("\nHave succesfully pushed: %d to queue", newNode->value);
        return;
    } else{
        // update the final item in the queue to point to the newNode
        queue->finishNode->next = newNode;

        // update the queue with the new final node and size
        queue->finishNode = newNode;
        queue->size++;

        printf("\nHave succesfully pushed: %d to queue", newNode->value);
    }
}

/**
 * Pops the top node from the queue
 * @params  {queue_t*}  queue   The queue to pop from
 * @return  {node_t*}           The top node from the queue
*/
node_t* removeNode(queue_t* queue){
    if(queue->size > 0){
        // save the current start node to return it
        node_t* returnNode = queue->startNode;

        // move the head to point to the next item
        queue->startNode = queue->startNode->next;

        // decrease the size of the queue
        queue->size--;

        // if the queue has no items, update the finishNode pointer to NULL
        if (queue->size == 0){
            queue->finishNode = NULL;
        }

        // return the top node
        return returnNode;
    } else{
        printf("\nError: queue is empty. Cannot pop item from queue");
        return NULL;
    }

}

/**
 * Returns the first node from a queue
 * @params  {queue_t*}  queue   The queue to peek at
 * @return  {node_t*}           The first node from the queue
*/
node_t* peek(queue_t* queue){
    return queue->startNode;
}

/**
 * Pops the top node from the queue
 * @params  {queue_t*}  queue   The queue to pop from
 * @return  {node_t*}           The top node from the queue
*/
bool isEmpty(queue_t* queue){
    if(queue->size > 0){
        return false;
    } else{
        return true;
    }
}

int main(void){
    node_t* poppedNode = NULL;
    node_t* peekNode = NULL;

    queue_t* queue = createQueue();
    add(queue, 1);
    add(queue, 7);

    poppedNode = removeNode(queue);
    printf("\nPopped node has value: %d", poppedNode->value);

    add(queue,3);
    add(queue,4);
    peekNode = peek(queue);
    printf("\nPeek node has value: %d", peekNode->value);

    poppedNode = removeNode(queue);
    printf("\nPopped node has value: %d", poppedNode->value);


    return 0;
}