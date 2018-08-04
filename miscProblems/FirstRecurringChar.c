/**
 * This question was posed by a youtube video. It should return the first recurring char in a string
 * e.g. 'ABCAD' would return 'A'
 * 'ABC' would return 'null'
 * 'ABCCA' would return 'C'
 * 
*/

#include <stdio.h>

char firstCharacter(char string[]);

struct charTable {
    char character;
    int count;
};

int main(){
    char testArray[] = {"ABCDA"};

    printf("Hello world");

    return 0;
}

char firstCharacter(char string[]) {
    struct charTable *hashTable = (struct charTable *)malloc(sizeof(struct charTable));

    for (int i = 0; i < strlen(string); i++){
        hashTable.put(string[i]);
    }

}

void hashCode(char key[]){
    
}






