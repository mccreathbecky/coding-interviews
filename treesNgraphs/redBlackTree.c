/**
 * A Red-Black Tree Implementation
 * Following a youtube video
*/

#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"


node_t* createNode(int value);
void rotateRight(node_t* root);

int main(void){
    node_t* root = createNode(10);
    insert(root, 10);
    insert(root, 5);
    insert(root, 2);
    insert(root, 8);
    insert(root, 6);
    insert(root, 9);
    insert(root, 12);

    printf("\nMy First Tree InOrder");
    inorderTraversal(root);
    printf("\nMy First Tree preorder");
    preorderTraversal(root);
    printf("\nMy First Tree postOrder");
    postorderTraversal(root);

    printf("\n**\nBefore rotate right\n");
    inorderTraversal(root);
    rotateRight(root);
    printf("\nAfter rotate right\n");
    inorderTraversal(root);
    return 0;
}

/**
 * Allocates memory and returns a newly created node with the specified value
 * @params {int} value The value to insert
 */
node_t* createNode(int value){
    node_t* node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Inserts a new node into the tree based on whether the value is bigger/smaller than the root value
 * @params {node_t *} root The root node to start from
 *         {int} value The value to insert
 */
void insert(node_t* root, int value){
    // if the value is smaller than the root, go left
    if(value <= root->value){
        if(root->left == NULL){
            root->left = createNode(value);
        } else{
            insert(root->left, value);
        }
    } else{
         if(root->right == NULL){
            root->right = createNode(value);
        } else{
            insert(root->right, value);
        }       
    }
}

/**
 *  Returns true if the passed value is anywhere in the tree
 * @params {node_t *} root The root node to check in
 *         {int} value The value to check for
 * @returns True if the value is found in the tree
 */
bool containsValue(node_t* root, int value){
    if(root->value == value){
        return true;
    } else if (value < root->value){
        if(root->left != NULL){
            return containsValue(root->left, value);
        } else {
            return false;
        }
    } else {
        if(root->right != NULL){
            return containsValue(root->right, value);
        } else{
            return false;
        }
    }
}

/**
 *  Prints all elements of the node out, starting with the left, then the root, then the right. 
 * @params {node_t *} root The root node to print from
 */
void inorderTraversal(node_t* root){
    if(root->left != NULL){
        printf("\nLeft: ");
        inorderTraversal(root->left);
        printf("\n\t");
    } 

    printf("Value: %d", root->value);

    if(root->right != NULL){
        printf("\n\t\tRight: ");
        inorderTraversal(root->right);
        printf("\n");
    }
}

/**
 *  Prints all elements of the node out, starting with the root, then the left, then the right
 * @params {node_t *} root The root node to print from
 */
void preorderTraversal(node_t* root){

    printf("\n\tValue: %d", root->value);

    if(root->left != NULL){
        printf("\nLeft: ");
        inorderTraversal(root->left);
        printf("\t");
    } 

    if(root->right != NULL){
        printf("\n\t\tRight: ");
        inorderTraversal(root->right);
    }
}

/**
 *  Prints all elements of the node out, starting with the left, then right, then root
 * @params {node_t *} root The root node to print from
 */
void postorderTraversal(node_t* root){
    if(root->left != NULL){
        printf("\nLeft: ");
        inorderTraversal(root->left);
        printf("\t");
    } 

    if(root->right != NULL){
        printf("\n\t\tRight: ");
        inorderTraversal(root->right);
        printf("\t");
    }

    printf("Value: %d", root->value);
}


/**
 * Rotates right from the root node
 * @params {node_t *} root The root node to rotate from
 */
void rotateRight(node_t* root){
    node_t* newRight = root;
    node_t* newRoot = root->left;
    node_t* newRightLeft = newRoot->right;

    root = newRoot;
    root->right = newRight;
    newRight->left = newRightLeft;
}
