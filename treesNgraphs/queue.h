/**
 * Basic queue implementation
*/

typedef struct{
    int value;
    struct node_t* next;
}node_t;


typedef struct{
    int size;
    node_t* startNode;
    node_t* finishNode;
}queue_t;


/**
 * Creates a new queue
 * @returns {queue_t*}  A pointer to a new queue
*/
queue_t* createQueue();

/**
 * Adds a new node to the end of the queue
 * @params  {queue_t*}  queue   The queue to add to
 *          {int}       val     The value to add to the new node
*/
void add(queue_t* queue, int val);

/**
 * Pops the top node from the queue
 * @params  {queue_t*}  queue   The queue to pop from
 * @return  {node_t*}           The top node from the queue
*/
node_t* removeNode(queue_t* queue);

/**
 * Returns the first node from a queue
 * @params  {queue_t*}  queue   The queue to peek at
 * @return  {node_t*}           The first node from the queue
*/
node_t* peek(queue_t* queue);

/**
 * Pops the top node from the queue
 * @params  {queue_t*}  queue   The queue to pop from
 * @return  {node_t*}           The top node from the queue
*/
bool isEmpty(queue_t* queue);
