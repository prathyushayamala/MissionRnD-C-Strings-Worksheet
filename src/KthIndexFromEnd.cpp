/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<conio.h>
#include<stdio.h>
char KthIndexFromEnd(char *str, int K) {
	if ((str == "") || (str == NULL)){
		return '\0';
	}
	else{
	int len = 0;
	while (str[len] != '\0'){
		len++;
	}
			if ((K >= 0) && (K <= len)){
				return str[len - K - 1];
			}
			else{
				return '\0';
			}
		}
	}