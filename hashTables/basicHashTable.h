/**
 * Functionality needed to use and access a hash table
*/

#define M 100

typedef struct{
    int key;
    int value;
    struct record_t* nextRecord;
} record_t;


/**
 * Creates a hashTable and returns a pointer to it
 * @returns {record_t **} The new hashTable
 */
record_t** createHashTable();

/**
 * Creates a new record based on the value given, and inserts it to the hashTable provided
 * @params {record_t**} table A hashTable to insert the record into
 *         {int} value The value to add to the hashTable, which will use the hashFunction to determine the key
 */
void insertRecord(record_t** table, int value);

/**
 * Searches through a hashTable for a record with the value provided
 * @params {record_t**} table A hashTable to search within
 *         {int} searchKey A value to which the hashFunction will be applied to search for a record
 * @return {record_t*} A pointer to the matching record, or NULL
 */
record_t* searchRecord(record_t** table, int searchKey);


/**
 * Prints a single record from a hashTable
 * @params {record_t**} table A hashTable containing the record
 *         {int} searchKey The value to use to locate the record from within the hashTable
 */
void printRecord(record_t** table, int searchKey);


/**
 * Prints all non-NULL records from a hashTable
 * @params {record_t**} table A hashTable to print from
 */
void printTable(record_t** table);

/**
 * Deletes an existing record from a hashTable, ensuring it takes into account the linkedList monitoring collisions
 * @params {record_t**} table A hashTable to delete the record from
 *         {int} value The value to remove from the hashTable, which will use the hashFunction to determine the key
 */
void deleteRecord(record_t** table, int value);

/**
 * Deletes all records from a table included those in a linkedList
 * @params {record_t**} table A hashTable to delete
 */
void deleteTable(record_t** table);

