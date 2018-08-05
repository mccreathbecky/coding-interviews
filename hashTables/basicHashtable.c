/**
 * Attempt #3 to create a hash table from scratch
 * We're starting basic and trying to stay with arrays
 * Much credit to: https://medium.com/@bartobri/hash-crash-the-basics-of-hash-tables-bef82a8ea550
 */

#include<stdio.h>

#define ISDEBUG 1
#define M 100

typedef struct{
    int key;
    int value;
    struct record_t* nextRecord;
} record_t;


int hashFunction(int key);
record_t** createHashTable();
record_t* newRecord(int value);
void insertRecord(record_t** table, int value);
void deleteRecord(record_t** table, int value);
record_t* searchRecord(record_t** table, int searchKey);
void printRecord(record_t** table, int searchKey);
void printTableRecord(record_t** table, int index);
void printTable(record_t** table);

int hashFunction(int key){
    return key%M;
}

/**
 * Creates a hashTable and returns a pointer to it
 * @returns {record_t **} The new hashTable
 */
record_t** createHashTable(){
    record_t** newTable = (record_t**)malloc(sizeof(record_t)*M);
    for (int i = 0; i<M; i++){
        newTable[i]=NULL;
    }
    return newTable;
}

/**
 * Initialises a new record based on the value provided [not yet added to a hashTable]
 * @params {int} value The value to use to create the new record
 */
record_t* newRecord(int value){
    record_t* rec = (record_t*)malloc(sizeof(record_t));
    rec->key = hashFunction(value);
    rec->value = value;
    rec->nextRecord = NULL;
    if(ISDEBUG) printf("\n++New record created with key: %d, value: %d", rec->key, rec->value);
    return rec;
}

/**
 * Creates a new record based on the value given, and inserts it to the hashTable provided
 * @params {record_t**} table A hashTable to insert the record into
 *         {int} value The value to add to the hashTable, which will use the hashFunction to determine the key
 */
void insertRecord(record_t** table, int value){

    // create the new record, but don't yet insert it into the table
    record_t* newRec = newRecord(value);  

    // check whether another record exists at this key value
    int hashValue = hashFunction(value);
    record_t* curRecord = table[hashValue];

    // if another record exists, use collision strategy to move through from the first record at that key
    if(curRecord != NULL){

        // keep moving to the next record until it's null
        while (curRecord->nextRecord != NULL){
            curRecord = curRecord->nextRecord;
        }

        // now that the next record is null, insert the newRecord at that position in the table
        curRecord->nextRecord = newRec;
    } else {
        // if there's no collision, simply insert the newRec into the table
        table[hashValue] = newRec;
    }
}



/**
 * Searches through a hashTable for a record with the value provided
 * @params {record_t**} table A hashTable to search within
 *         {int} searchKey A value to which the hashFunction will be applied to search for a record
 * @return {record_t*} A pointer to the matching record, or NULL
 */
record_t* searchRecord(record_t** table, int searchKey){
    record_t* searchRec;

    int key = hashFunction(searchKey);
    searchRec = table[key];

    // if no record exists at the hashFunction, return NULL
    if(searchRec == NULL){
        return searchRec;
    }

    // if a record was found but doesn't match the searchKey, move through the records using collision detection
    if(searchRec != NULL && searchRec->value != searchKey){
        while(searchRec->value != searchKey && searchRec->nextRecord != NULL){
            if(ISDEBUG) printf("\nMoving through records at key: %d", searchRec->key);
            searchRec = searchRec->nextRecord;
        }
    }

    // confirm that the correct record was found and return it
    if (searchRec->value == searchKey){
        if(ISDEBUG) printf("\nRecord found. Key: %d, value: %d", searchRec->key, searchRec->value);
        return searchRec;
    } else {
        return NULL;
    }
}

/**
 * Prints a single record from a hashTable
 * @params {record_t**} table A hashTable containing the record
 *         {int} searchKey The value to use to locate the record from within the hashTable
 */
void printRecord(record_t** table, int searchKey){
    record_t* rec = searchRecord(table, searchKey);
    if(rec!=NULL){
        printf("\n[%d]: value: %d", rec->key, rec->value);
    }
}


/**
 * Prints all non-NULL records from a hashTable including moving through linkedLists
 * @params {record_t**} table A hashTable to print from
 *         {int} index The current hashTable index to check for records in
 */
void printTableRecord(record_t** table, int index){

    record_t* rec = table[index];

    if (rec == NULL){
        return;
    } else {
        printf("\n\t[%d]: %d", rec->key, rec->value);

        while(rec->nextRecord!=NULL){
            rec = rec->nextRecord;
            printf("\n\t[%d]: %d", rec->key, rec->value);
        }
    }
}

/**
 * Prints all non-NULL records from a hashTable
 * @params {record_t**} table A hashTable to print from
 */
void printTable(record_t** table){
    printf("\nNow printing table: ");
    for(int i = 0; i<M; i++){
        printTableRecord(table, i);
    }
}


/**
 * Deletes an existing record from a hashTable, ensuring it takes into account the linkedList monitoring collisions
 * @params {record_t**} table A hashTable to delete the record from
 *         {int} value The value to remove from the hashTable, which will use the hashFunction to determine the key
 */
void deleteRecord(record_t** table, int value){
    record_t* curRec = table[hashFunction(value)];
    record_t* prevRec = NULL;
    record_t* tempRec = NULL;

    // check if the record exists
    if (curRec == NULL){
        return;
    } else {
        // if the record exists, search through until the correct one is found using collision detection
        while (curRec->value != value && curRec->nextRecord != NULL){
            // save the currentRecord to reconnect the pointers in the linkedList later if needed
            prevRec = curRec;
            curRec = curRec->nextRecord;
        }

        // if in looping through the linkedList, the correct value was not found, exit with error
        if(curRec->value != value){
            printf("\nValue not found");
            return;
        }

        // reconnect the pointers in the linkedList if needed
        if(curRec->nextRecord!= NULL){
            // if theres more records to follow and this is the first record of the linkedList 
            // e.g. 217->17->317 and we're removing 217, must connect table to 17
            if(prevRec == NULL){
                // set the next record to the current one
                if(ISDEBUG) printf("\n--Now deleting record[%d]: %d and updating with nextRecord", curRec->key, curRec->value);
                tempRec = curRec;
                curRec = curRec->nextRecord;
                table[hashFunction(value)] = curRec;
                free(tempRec);
            }
            // else if there's more records before and after this one, set the one before to have 'nextRecord' as the one after
            // e.g. 217->17->317 and we're removing 17, must connect 217->317
            else {
                printf("\n--Now deleting record[%d]: %d and adjusting pointers on either side", curRec->key, curRec->value);
                tempRec = curRec;
                // set the previous record to skip this record and use the nextRecord as its next value
                prevRec->nextRecord = curRec->nextRecord;
                free(tempRec);
            }
        } else{
            // no need to reconnect pointers, simply free up the space
            // e.g. if there's only 217 at this index and we're removing it
            table[hashFunction(curRec->value)] = NULL;
            free(curRec);
            if(ISDEBUG) printf("\n--Record with value: %d now deleted", value);
        }
    } 


}

/**
 * Deletes an existing record from a hashTable
 * @params {record_t**} table A hashTable to delete the record from
 *         {int} value The value to remove from the hashTable, which will use the hashFunction to determine the key
 */
void deleteTableRecord(record_t** table, int index){
    record_t* curRec = table[hashFunction(index)];
    record_t* freeRec;

    if (curRec == NULL){
        return;
    } else {
        // check if the record exists and free all records in that index
        while (curRec != NULL){
            freeRec = curRec;
            if(ISDEBUG) printf("\n--Record[%d] with value: %d about to be deleted", index, freeRec->value);

            curRec = curRec->nextRecord;

            freeRec->key=NULL;
            freeRec->value=NULL;
            freeRec->nextRecord=NULL;
            free(freeRec);
        }
    } 

    table[index]=NULL;
    free(table[index]);
}


void deleteTable(record_t** table){
    for(int i = 0; i<M; i++){
        deleteTableRecord(table,i);
    }
    free(table);
}

int main(void){
    record_t** hashTable = createHashTable();
    insertRecord(hashTable,318);
    insertRecord(hashTable,18);
    insertRecord(hashTable,218);
    insertRecord(hashTable,17);
    insertRecord(hashTable,217);
    insertRecord(hashTable,1);
    insertRecord(hashTable,101);

    printTable(hashTable);

    deleteRecord(hashTable,18);
    printTable(hashTable);

    deleteRecord(hashTable,17);
    deleteRecord(hashTable,180);
    insertRecord(hashTable,180);
    insertRecord(hashTable,182);
    printTable(hashTable);

    return 0;
}

