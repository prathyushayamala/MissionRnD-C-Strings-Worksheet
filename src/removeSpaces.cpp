/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char* remove_space(char *str, int index){//to do left shift of the string by one unit
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
		while (str[len] != '\0'){//calculating the length of the string
			len++;
		}

		while (str[i] != '\0'){//finding the space and calling function to remove it
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