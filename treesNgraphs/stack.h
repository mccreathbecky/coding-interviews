/**
 * Basic stack implementation
*/

typedef struct{
    int value;
    struct node_t* next;
}node_t;

typedef struct{
    int size;
    node_t* topNode;
}stack_t;


/**
 * Creates a new stack
 * @returns {stack_t*}  A pointer to a new stack
*/
stack_t* createStack();

/**
 * Pushes a new node to the top of the stack, pushing all existing nodes further down
 * @params  {stack_t*}  stack   The stack to add to
 *          {int}       val     The value to add to the new node
*/
void push(stack_t* stack, int val);

/**
 * Pops the top node from the stack
 * @params  {stack_t*}  stack   The stack to pop from
 * @return  {node_t*}           The top node from the stack
*/
node_t* pop(stack_t* stack);

/**
 * Returns the top node from a stack
 * @params  {stack_t*}  stack   The stack to peek at
 * @return  {node_t*}           The top node from the stack
*/
node_t* peek(stack_t* stack);

/**
 * Pops the top node from the stack
 * @params  {stack_t*}  stack   The stack to pop from
 * @return  {node_t*}           The top node from the stack
*/
bool isEmpty(stack_t* stack);

