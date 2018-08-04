#include <stdio.h>
#include <stdlib.h>

#define HT_PRIME_1 18287
#define HT_PRIME_2 19423

typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

static ht_item HT_DELETED_ITEM = {NULL, NULL};

static ht_item* ht_new_item(const char* k, const char* v) {
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    printf("Hash table item created\t");
    return i;
}

ht_hash_table* ht_new(){
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    printf("Hash table created\n");
    return ht;
}

static void ht_del_item(ht_item* i){
    free(i->key);
    free(i->value);
    free(i);
    printf("Hash table item deleted");
}

void ht_del_hash_table(ht_hash_table* ht){
    for (int j = 0; j > ht->size; j++){
        ht_item* item = ht->items[j];
        if(item != NULL) {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
    printf("Hash table deleted\n");
}

static int ht_hash(const char* s, const int primeNb, const int mod) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++){
        hash += (long)pow(primeNb, len_s - (i+1)) * s[i];
        hash = hash % primeNb;
    }
    return (int)hash;
}

static int ht_get_hash(const char *s, const int num_buckets, const int attempt){
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;

}

void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL) {
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    } 
    ht->items[index] = item;
    ht->count++;
}
// void ht_insert(ht_hash_table* ht, const char* key, const char* value){
//     ht_item* item = ht_new_item(key,value);
//     int index = ht_get_hash(item->key, ht->size, 0);
//     ht_item* cur_item = ht->items[index];
//     while(cur_item!=NULL){
//         if (cur_item != &HT_DELETED_ITEM){
//             if(strcmp(cur_item->key, key) == 0){
//                 ht_del_item(cur_item);
//                 ht->items[index] = item;
//                 return;
//             }
//         }
//     }
//     ht->items[index] = item;
//     ht->count++;
// }

char* ht_search(ht_hash_table* ht, const char* key){
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL){
        if (item != &HT_DELETED_ITEM){
            if(strcmp(item->key, key) == 0){
                return item->value;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}

void ht_delete(ht_hash_table* ht, const char* key){
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (item != &HT_DELETED_ITEM) {
            if(strcmp(item->key, key) == 0) {
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
                ht->count--;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
}

void ht_print(ht_hash_table* ht){
    printf("\nht size: %d, ht count: %d", ht->size, ht->count);
    for (int i = 0; i < ht->count; i++){
        printf("\ni: %d", i);
        printf("\nKey: %s, Value: %s", ht->items[i]->key, ht->items[i]->value);
    }
}


//********************************************************
//********************************************************
//********************************************************

int main() {
    ht_hash_table* ht = ht_new();
    ht_insert(ht, "cats", "very good");
    ht_print(ht);
    ht_insert(ht, "dogs", "quite good");
    ht_print(ht);
    ht_insert(ht, "mice", "alright good");
    ht_print(ht);
    ht_insert(ht, "mice2", "alright good");
    ht_print(ht);
    printf("\nhash table theoretically created");
    ht_del_hash_table(ht);
    return 0;
}