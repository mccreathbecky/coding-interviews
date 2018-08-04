/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include <stdio.h>

#define MAXSIZE 100

int lengthOfLongestSubstring(char* s);

int main(){

	char sampleString[] = "abcabcbb";

	int length = lengthOfLongestSubstring(sampleString);


	printf("Length is: %d", length);
	return length;
}


int lengthOfLongestSubstring(char* s) {
	char subString[MAXSIZE];
	int maxLength = 0;

	for (int i = 0; s[i] != '\0'; i++){
		if (maxLength == 0 && (s[i+1] != s[i])) {
			maxLength++;
			// subString
		}
		else if (maxLength > 0) {
		
		}
		
	}


    return maxLength;
}