/**
 * Basic stack and queue implementation
*/

#include <stdio.h>

typedef struct{
    int value;
    struct node_t* next;
}node_t;

typedef struct{
    int size;
    node_t* topNode;
}stack_t;


/**
 * Creates a new node with the passed value
 * @params  {int}       val     The value to add to the new node
 * @return  {node_t*}   The newly created node
*/
node_t* createNode(int val){
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->value = val;
    node->next = NULL;
    return node;
}

/**
 * Creates a new stack
 * @returns {stack_t*}  A pointer to a new stack
*/
stack_t* createStack(){
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    stack->size = 0;
    stack->topNode = NULL;
    return stack;
}

/**
 * Pushes a new node to the top of the stack, pushing all existing nodes further down
 * @params  {stack_t*}  stack   The stack to add to
 *          {int}       val     The value to add to the new node
*/
void push(stack_t* stack, int val){
    node_t* newNode = createNode(val);
    newNode->next=stack->topNode;
    stack->topNode=newNode;
    stack->size++;
    printf("\nHave succesfully pushed: %d to stack", newNode->value);
}

/**
 * Pops the top node from the stack
 * @params  {stack_t*}  stack   The stack to pop from
 * @return  {node_t*}           The top node from the stack
*/
node_t* pop(stack_t* stack){
    if(stack->size > 0){
        node_t* returnNode = stack->topNode;
        stack->topNode = stack->topNode->next;
        stack->size--;
        return returnNode;
    } else{
        printf("\nError: Stack is empty. Cannot pop item from stack");
    }

}

int main(void){
    stack_t* stack = createStack();
    push(stack, 1);
    push(stack, 7);


    node_t* poppedNode = pop(stack);
    printf("\nPopped node has value: %d", poppedNode->value);

    push(stack,3);
    push(stack,4);
    push(stack,5);

    poppedNode = pop(stack);
    printf("\nPopped node has value: %d", poppedNode->value);


    return 0;
}