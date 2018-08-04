/**
 * Create a hashset using the provided functions
 * 
 * This is a work in progress HashTable Example based on an online tutorial
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXVALUE 1000000
#define MAXRANGE 10000

typedef struct {
    int key;
} HashItem;

typedef struct {
    int count;
    HashItem** hashItems;
} MyHashSet;

static HashItem* deletedItem = {NULL};

MyHashSet* myHashSetCreate();
void myHashSetAdd(MyHashSet* obj, int key);
void myHashSetRemove(MyHashSet* obj, int key);
bool myHashSetContains(MyHashSet* obj, int key);
void myHashSetFree(MyHashSet* obj);
void printMyHashSet(MyHashSet* obj);

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* newHS = malloc(sizeof(MyHashSet));
    newHS->count = 0;
    newHS->hashItems = calloc((size_t)MAXRANGE, sizeof(HashItem*));
    
    printf("\nnewHS created");
    return newHS;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    HashItem* newItem = malloc(sizeof(HashItem));
    newItem->key = key;
    obj->hashItems[obj->count] = newItem;
    obj->count++;
    printf("\nNew item added");
}

void myHashSetRemove(MyHashSet* obj, int key) {
    HashItem* curItem = obj->hashItems[0];
    for(int i = 0; i <= obj->count && curItem != NULL; i++, curItem = obj->hashItems[i]){
        printf("\ni:%d, cur_item->key: %d, removeKey: %d", i, curItem->key, key);
        if (curItem->key == key) {
            printf("\nfound item to remove");
            free(obj->hashItems[i]);
            obj->hashItems[i]=&deletedItem;
            printf("\nFreed current item");
            obj->count--;
        }
    }
}

void printMyHashSet(MyHashSet* obj) {
    HashItem* curItem = obj->hashItems[0];
    printf("\nMyHashSet contains %d items:", obj->count);
    for (int i = 0; i < obj->count && curItem != NULL; i++, curItem = obj->hashItems[i]) {
        printf("\n#%d:%d", i, curItem->key);
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    // free(obj->count);
    // free(obj);
    printf("\nMyHashSetFree run");
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * struct MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 * myHashSetRemove(obj, key);
 * bool param_3 = myHashSetContains(obj, key);
 * myHashSetFree(obj);
 */
int main(){
    printf("\nHello World");
    struct MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj,3);
    myHashSetAdd(obj,4);
    myHashSetAdd(obj,7);
    printMyHashSet(obj);
    myHashSetRemove(obj,3);
    printMyHashSet(obj);
    return 0;
}

