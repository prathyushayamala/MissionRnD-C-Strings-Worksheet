/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
//comparision of given two strings and returning the common word to the result array
 char** compare(char** words_in_str1, char** words_in_str2,char** res,int no_of_words_in_str1,int no_of_words_in_str2){
	int i = 0, j = 0,k=0,l=0,common_words_count=0;
	for (i = 0; i <= no_of_words_in_str1; i++){
		for (j = 0; j <= no_of_words_in_str2; j++){
			if (words_in_str2[j][k] == '\0'){
				break;
			}
			if ((words_in_str1[i] != '\0') && (words_in_str2[j] != '\0')){
				if (words_in_str1[i][k] == words_in_str2[j][k]){
					common_words_count++;
						res[l] = words_in_str1[i];
						l++;
				}
			}
		}
		if (words_in_str1[i][k] == '\0'){
			break;
		}
	}
	res[l] = NULL;
	if (common_words_count== 0){
		res = NULL;
	}
	return res;
}

char ** commonWords(char *str1, char *str2) {
	int i=0,j=0,k=0,no_of_words_in_str1=0,no_of_words_in_str2=0,len1=0,len2=0;
	char **words_in_str1, **words_in_str2, **res;
	if ((str1 == '\0') || (str2 == '\0')){
		return NULL;
	}
	else{
		while (str1[i] != '\0'){//calculating number of words in the first string
			if (str1[i] == ' '){
				no_of_words_in_str1++;
			}
			i++;
		}
		len1 = i;
		i = 0;
		while (str2[i] != '\0'){//calculating number of words in the second string
			if (str2[i] == ' '){
				no_of_words_in_str2++;
			}
			i++;
		}
	}
	len2 = i;
	words_in_str1 = (char**)malloc(len1*sizeof(char));
	words_in_str2 = (char**)malloc(len2*sizeof(char));
	for (i = 0; i <= no_of_words_in_str1; i++){
		words_in_str1[i] = (char*)malloc(len1*sizeof(char));
		//words_in_str1[i] = '\0';
	}
	for (i = 0; i <= no_of_words_in_str2; i++){
		words_in_str2[i] = (char*)malloc(len2*sizeof(char));
		//words_in_str2[i] = '\0';
	}
	i = 0;
	while (str1[i] != '\0'){
		if (str1[i] != ' '){
			words_in_str1[j][k] = str1[i];
			printf("%c", words_in_str1[j][k]);
			k++;
		}
		else{
			words_in_str1[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	i = 0, j = 0, k = 0;
	while (str2[i] != '\0'){
		if (str2[i] != ' '){
			words_in_str2[j][k] = str2[i];
			printf("%c", words_in_str2[j][k]);
			k++;
		}
		else{
			words_in_str2[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	//sufficient allocation of the memory to result
	if (no_of_words_in_str1 >= no_of_words_in_str2){
		if (len1 > len2){
			res = (char**)malloc(len1*sizeof(char));
			for (i = 0; i <= no_of_words_in_str1; i++){
				res[i] = (char*)malloc(len1*sizeof(char));
			}
		}
		else{
			res = (char**)malloc(len2*sizeof(char));
			for (i = 0; i <= no_of_words_in_str1; i++){
				res[i] = (char*)malloc(len2*sizeof(char));
			}
		}
	}
	else{
		if (len1 > len2){
			res = (char**)malloc(len1*sizeof(char));
			for (i = 0; i <= no_of_words_in_str2; i++){
				res[i] = (char*)malloc(len1*sizeof(char));
			}
		}
		else{
			res = (char**)malloc(len2*sizeof(char));
			for (i = 0; i <= no_of_words_in_str2; i++){
				res[i] = (char*)malloc(len2*sizeof(char));
			}
		}

	}
	res = compare(words_in_str1, words_in_str2,res, no_of_words_in_str1, no_of_words_in_str2);
	return res;
}