/**
 * My first tree
 * Attempting to follow concept explained here: https://www.youtube.com/watch?v=oSWTXtMglKE
 * And implement with in-order traversal
*/

typedef struct{
    int value;
    struct node_t* left;
    struct node_t* right;
}node_t;

/**
 * Inserts a new node into the tree based on whether the value is bigger/smaller than the root value
 * @params {node_t *} root The root node to start from
 *         {int} value The value to insert
 */
void insert(node_t* root, int value);

/**
 *  Returns true if the passed value is anywhere in the tree
 * @params {node_t *} root The root node to check in
 *         {int} value The value to check for
 * @returns True if the value is found in the tree
 */
bool containsValue(node_t* root, int value);

/**
 *  Prints all elements of the node out, starting with the left, then the root, then the right. 
 * @params {node_t *} root The root node to print from
 */
void inorderTraversal(node_t* root);

/**
 *  Prints all elements of the node out, starting with the root, then the left, then the right
 * @params {node_t *} root The root node to print from
 */
void preorderTraversal(node_t* root);

/**
 *  Prints all elements of the node out, starting with the left, then right, then root
 * @params {node_t *} root The root node to print from
 */
void postorderTraversal(node_t* root);