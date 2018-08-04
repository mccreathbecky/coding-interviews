/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

bool isInSubstring(char* sub, char comp);
int lengthOfLongestSubstring(char* s);

int main(){
	// char sampleString[] = "abcabcbb";
	// char sampleString[] = "bbbb";
	char sampleString[] = "pwwkew";
	printf("\nString is: %s", sampleString);
	int length = lengthOfLongestSubstring(sampleString);

	return length;
}

/**
 * Determine whether a single char is in a string
 * @params {char *} sub A string to check through
 * 		   {char} comp A single character to compare
 * @return {bool} True if the character is in the subString
*/
bool isInSubstring(char* sub, char comp){
	int i = 0;
	while(sub[i] != '\0'){
		if(sub[i] == comp){
			return true;
		}
		else{
			i++;
		}
	}
	return false;
} 

/**
 * Determines the length of the longest subString
 * @params {char *} sub A string to check through
 * @return {int} The length of the longest subString
*/
int lengthOfLongestSubstring(char* s) {
	// start with the first character and store it as a substring, set length to 1
	char firstSub[MAXSIZE] = {'\0'};
	firstSub[0] = s[0];
	int firstLength = 1;

	char secondSub[MAXSIZE] = {'\0'};
	int secondLength = 0;

	int startStr = 0;
	int index = 1;

	int count = 0;
	// work through until you hit a null character
	while(s[index] != '\0' && count<100){

		// if the next character is the same as any of the current characters
		// save it as the start of a new subString
		if(isInSubstring(firstSub, s[index])){
			printf("\nnew char: %c is in existing subString",s[index]);
			secondSub[0]=s[index];
			secondLength=1;
		}
		// if it's a new character, and consecutive to the currentString, add it to the subString and increase maxLength
		else if(index == firstLength){
			firstSub[index] = s[index];
			firstLength++;
			printf("\nsubString is: %s", firstSub);
			printf("\nfirstLength is now: %d", firstLength);
		}
		// it's a new character non-consecutively, continue the new subString and update it to the mainString if longer
		else{
			secondSub[secondLength++] = s[index];
			printf("\nfirstSub is: %s", firstSub);
			printf("\nsecondSub is: %s", secondSub);
			if(secondLength>firstLength){
				memcpy(firstSub,secondSub,secondLength);
				firstLength = secondLength;
				secondLength = 0;
			}

		}
		index++;
		count++;
	}

	printf("\nLongest Substring is: %s, Length: %d", firstSub, firstLength);
    return firstLength;
}