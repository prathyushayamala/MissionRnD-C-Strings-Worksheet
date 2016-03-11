/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char* remove_space(char *str, int index){
	int j = index+1;
	while (str[j] != '\0'){
		str[j - 1] = str[j];
		j++;
	}
	return str;
}
char removeSpaces(char *str) {
	int len = 0,i=0;
	if (str == '\0'){
		return '\0';
	}
	else{
		while (str[len] != '\0'){
			len++;
		}

		while (str[i] != '\0'){
			if (str[i] == ' '){
				str = remove_space(str, i);
				str[len--] = '\0';
				i = i - 1;
			}
			i++;
		}
		return (char)str;
	}
}